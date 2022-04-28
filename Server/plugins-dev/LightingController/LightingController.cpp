#include "LightingController.h"
#include "SunsetTimes.h"
#include "../../ServerCoreModules/CoreModules/TaskList/WeekdaySchedual.h"

#include "rapidjson/document.h"
#include "../../ServerCoreModules/CoreModules/Comms/JSON/ToJsonHelper.h"


LightingController::LightingController(CoreModules* cm):
    Plugin(cm),
    m_sleeping(LoggerModel<bool>("Sleeping state change",false), 12),
    m_last_light_state("Light state change",false),
    m_last_brightness_state(LoggerModel<int>("Brightness state change", 100), 12) {

        auto comms = cm->getComms();
        auto router = comms->Router();

        router->RegisterPluginPage("Shiny-chan","plugins/Lighting_content");

        router->MapURLRequest(
            "/plugins/Lighting/AllLights",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            connection->Write("[{\"name\" : \"Bedroom\", \"state\" : \""+std::to_string(m_last_light_state.Get())+"\"}]");
        });

        router->MapURLRequest(
            "/plugins/Lighting/SleepingStatus",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            if(!m_sleeping.get().Get()){
               connection->Write("0");
               return;
            }
            connection->Write(std::to_string(m_sleeping.hoursUntilExpire()));

        });


        router->MapURLRequest(
            "/plugins/Lighting/TurnOnLight",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            std::map<std::string, std::string> params = connection->RequestParams();
            if(params.find("name") == params.end()){
                ErrorLogger::logError("name not found in params list");
                return;
            }
            auto light = params["name"];

            turnOnLight(light, m_last_brightness_state.get().Get());

            connection->Write(statusToJson());
        });

        router->MapURLRequest(
            "/plugins/Lighting/TurnOffLight",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto params = connection->RequestParams();
            auto light = params["name"];
            turnOffLight(light);

            connection->Write(statusToJson());
            
        });

        router->MapURLRequest(
            "/plugins/Lighting/Sleeping",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto model = m_sleeping.get();
            if(connection->RequestBody() == "true"){
                model.Set(true);
                m_sleeping.set(model);
                turnOffLight("Bedroom");
            } else {
                model.Set(false);
                m_sleeping.set(model);
                ErrorLogger::logInfo("Sleeping Un-Set");
            }
        });

        router->MapURLRequest(
            "/plugins/Lighting/SetBrightness",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto params = connection->RequestParams();
            std::string s_brightness = params["brightness"];
            int brightness = 0;
            try{
                brightness = std::stoi(s_brightness);
            } catch(std::invalid_argument e){
                ErrorLogger::logError("Invalid brightness value : "+s_brightness);
                return;
            }
            
            turnOnLight("bedroom", brightness);
            connection->Write(statusToJson());
        });

        auto motion = cm->getSensors().GetSensorByName("bedroom");
        if(motion != nullptr){
            motion->Motion([&](){this->bedroomMotion();});
        }else {
            ErrorLogger::logInfo("failed to attatch to bedroom sensor");
        }

        setupSchedule();
        

}

std::string LightingController::statusToJson(){
    Comms::JSON::ToJsonHelper jsonHelper;
    return jsonHelper.ToJson(
        {"name", "state", "brightness"},
        "Bedroom",
        m_last_light_state.Get(),
        m_last_brightness_state.get().Get()
    );
}

void LightingController::bedroomMotion(){
    SunsetTimes s;
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);

    if(s.IsSunDown() || local_tm.tm_hour >= 21){
        turnOnLight("bedroom", m_last_brightness_state.get().Get());
        
        if( !m_sleeping.get().Get() && 
                (local_tm.tm_hour < 21 &&
                 local_tm.tm_hour > 7
                )
        )
            {
            auto turn_off_time = std::chrono::system_clock::now() + 
                std::chrono::minutes(5);

            if( m_turn_off_light_task != nullptr && 
                m_turn_off_light_task->ChangeTime(turn_off_time)){
                
                ErrorLogger::logInfo("turn off time updated");
                return;
            }

            ErrorLogger::logInfo("Failed to update od expired");
            m_turn_off_light_task.reset();

            m_turn_off_light_task = std::make_shared<CallbackTask>(
                [&]() {
                    ErrorLogger::logInfo("attempting to turn off light");
                    turnOffLight("bedroom");
                },
                turn_off_time
            );

            coreMod->getScheduler()->ScheduleTask(m_turn_off_light_task);


        }
    } else {
        ErrorLogger::logInfo("motion detected but sun is up");
    }
}

bool LightingController::trySetLightState(
    bool state,
    int brightness){

    std::lock_guard<std::mutex> guard(m_node_mutex);


    if(m_last_light_state.Get() == state && m_last_brightness_state.get().Get() == brightness){
        ErrorLogger::logError("Attempted to set light to: " + std::to_string(state) + ", "+std::to_string(state)+
        " but was already in that state");
        return true;
    }

    bool exit_code = 0;

    for(auto& light : this->m_lights){

        std::stringstream cmd;
        cmd << "curl http://"<<light<<"/cm?cmnd=Backlog%20";

        if(state){
            cmd << "WHITE%20" <<std::to_string(brightness);
            cmd << "%3BPOWER%20ON";
        } else {
            cmd << "POWER%20OFF";
        }

        std::string output = this->coreMod->getTaskList()->RunSystemCommand(
            cmd.str(),
            exit_code
        );
        
        if(!exit_code ){
            ErrorLogger::logError("Failed to turn light on got exit code: " + std::to_string(exit_code));
        } else{
            m_last_light_state.Set(state);

            auto model = m_last_brightness_state.get();
            model.Set(brightness);
            m_last_brightness_state.set(model); // restarts timer
        }
    }

    return true;

}

void LightingController::turnOnLight(
    std::string name,
    int brightness
){  
    // dim the brightness if its after 9 if its not been set by the app
    if(m_last_brightness_state.isExpired()) {
        auto now = std::chrono::system_clock::now();
        time_t tt = std::chrono::system_clock::to_time_t(now);
        tm local_tm = *localtime(&tt);
        if(local_tm.tm_hour >= 21 || local_tm.tm_hour <= 7) {
            brightness = 40;
        }
    }
    
    if (!m_sleeping.get().Get()) { 

        int num_retrys = 3;
        for(int i = 0; i < num_retrys; ++i){
            if(trySetLightState(true, brightness)){
                return;
            }
        }

        ErrorLogger::logWarn("Failed to set light state on after all retrys");

    } else{
        ErrorLogger::logInfo("Attempted to turn on light but sleeping is set");
    }
}

void LightingController::turnOffLight(
    std::string name
){
    int num_retrys = 3;
    for(int i = 0; i < num_retrys; ++i){
        if(trySetLightState(false, m_last_brightness_state.get().Get())){
            return;
        }
    }

    ErrorLogger::logWarn("Failed to set light state off after all retrys");
}

void LightingController::setupSchedule(
) {
    m_schedual = std::make_shared<WeekdaySchedual>(
        coreMod->getScheduler()
    );
    m_schedual->Initialse(17, 0, [&](){
        SunsetTimes s;
        if(s.IsSunDown()){
            turnOnLight("bedroom", m_last_brightness_state.get().Get());
        }
    });
}

void LightingController::handleRequest(std::string requestURL){
    return;
}

const std::string LightingController::pluginName(){
    return "Lighting";
}
