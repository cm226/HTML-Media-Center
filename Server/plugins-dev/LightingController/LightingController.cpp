#include "LightingController.h"
#include "SunsetTimes.h"
#include "../../ServerCoreModules/CoreModules/TaskList/WeekdaySchedual.h"

#include "rapidjson/document.h"


LightingController::LightingController(CoreModules* cm):
    Plugin(cm),
    m_sleeping("Sleeping state change",false),
    m_last_light_state("Light state change",false) {

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
            if(!m_sleeping.Get()){
               connection->Write("0");
               return;
            }

            auto hours_since_sleeping = std::chrono::duration_cast<std::chrono::hours>(
                std::chrono::system_clock::now() - m_sleeping_at);

            connection->Write(std::to_string(
                    12 - hours_since_sleeping.count()
            ));

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

            turnOnLight(light);

            connection->Write("{\"name\" : \"Bedroom\", \"state\" : \""+std::to_string(m_last_light_state.Get())+"\"}");
        });

        router->MapURLRequest(
            "/plugins/Lighting/TurnOffLight",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto params = connection->RequestParams();
            auto light = params["name"];
            turnOffLight(light);

            connection->Write("{\"name\" : \"Bedroom\", \"state\" : \""+std::to_string(m_last_light_state.Get())+"\"}");
            
        });

        router->MapURLRequest(
            "/plugins/Lighting/Sleeping",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            if(connection->RequestBody() == "true"){
                m_sleeping_at = std::chrono::system_clock::now();
                m_sleeping.Set(true);
                turnOffLight("Bedroom");
            } else {
                m_sleeping.Set(false);
                
                ErrorLogger::logInfo("Sleeping Un-Set");
            }
            

            // turn off motion sensing untill morning. 
            // auto req = cm->getComms()->createJSONRequest();

            // SunsetTimes sunset;
            // auto sunset = sunset.nextSunSet();
            // req->requestURL("http://192.168.1.xx/?sleep="+std::to_string(sunset));
            // std::string reply;
            // if(!req->makeRequest(reply)){
            //     ErrorLogger::logInfo("Failed to talk to otion sensor to turn off");
            // }


        });


        auto motion = cm->getSensors().GetSensorByName("bedroom");
        if(motion != nullptr){
            motion->Motion([&](){this->bedroomMotion();});
        }else {
            ErrorLogger::logInfo("failed to attatch to bedroom sensor");
        }

        setupSchedule();
        

}

void LightingController::bedroomMotion(){
    SunsetTimes s;
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);

    if(s.IsSunDown() || local_tm.tm_hour >= 21){
        turnOnLight("bedroom");
        
        if( !m_sleeping.Get() && 
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
    int brightness
){
    std::lock_guard<std::mutex> guard(m_node_mutex);


    if(m_last_light_state.Get() == state){
        ErrorLogger::logError("Attempted to set light to: " + std::to_string(state) + 
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
        }
    }

    return true;

}

void LightingController::turnOnLight(
    std::string name
){  

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    if(std::chrono::duration_cast<std::chrono::hours>(
        now - m_sleeping_at) > std::chrono::hours(12)) {
            m_sleeping.Set(false);
            ErrorLogger::logInfo("Sleeping Unset");
    }

    // dim the brightness if its after 9
    int brightness = 100;
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);
    if(local_tm.tm_hour >= 21 || local_tm.tm_hour <= 7) {
        brightness = 40;
    }
    
    if (!m_sleeping.Get()) { 

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
        if(trySetLightState(false)){
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
            turnOnLight("bedroom");
        }
    });
}

void LightingController::handleRequest(std::string requestURL){
    return;
}

const std::string LightingController::pluginName(){
    return "Lighting";
}
