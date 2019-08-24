#include "LightingController.h"
#include "SunsetTimes.h"

#include "rapidjson/document.h"

LightingController::LightingController(CoreModules* cm):
    Plugin(cm),
    m_sleeping(false),
    m_last_light_state(false){

        auto comms = cm->getComms();
        auto router = comms->Router();

        router->RegisterWidgit("/plugins/Lighting_content/widgit.html");

        router->MapURLRequest(
            "/plugins/Lighting/AllLights",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            connection->Write("[{\"name\" : \"Bedroom\", \"state\" : \""+std::to_string(m_last_light_state)+"\"}]");
        });


        router->MapURLRequest(
            "/plugins/Lighting/TurnOnLight",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto params = connection->RequestParams();
            auto light = params["name"];

            if(std::chrono::system_clock::now() - m_sleeping_at > 
                std::chrono::hours(12)){
                    m_sleeping = false;
                    ErrorLogger::logInfo("Sleeping Unset");
            }

            turnOnLight(light);

            connection->Write("{\"name\" : \"Bedroom\", \"state\" : \""+std::to_string(m_last_light_state)+"\"}");
        });

        router->MapURLRequest(
            "/plugins/Lighting/TurnOffLight",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto params = connection->RequestParams();
            auto light = params["name"];
            turnOffLight(light);

            connection->Write("[{\"name\" : \"Bedroom\", \"state\" : \""+std::to_string(m_last_light_state)+"\"}]");
            
        });

        router->MapURLRequest(
            "/plugins/Lighting/Sleeping",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            m_sleeping_at = std::chrono::system_clock::now();
            m_sleeping = true;
            turnOffLight("Bedroom");
            m_last_light_state = false;
            
            ErrorLogger::logInfo("Sleeping Set");

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
        

}

void LightingController::bedroomMotion(){
    SunsetTimes s;
    if(s.IsSunDown()){
        turnOnLight("bedroom");
    }
}

void LightingController::turnOnLight(
    std::string name
){
    if(!m_sleeping){
        bool exit_code = 0;
        this->coreMod->getTaskList().RunSystemCommand(
            "node ControlLighting light="+name+" state=on",
            exit_code);
        
        if(exit_code != 0){
            ErrorLogger::logInfo("Failed to turn light on got exit code: " + std::to_string(exit_code));
        }

    } else{
        ErrorLogger::logInfo("Attempted to turn on light but sleeping is set");
    }
}

void LightingController::turnOffLight(
    std::string name
){
    bool exit_code = 0;
    std::string output = this->coreMod->getTaskList().RunSystemCommand(
        "node ControlLighting light="+name+" state=off",
        exit_code);

    if(exit_code != 0){
        ErrorLogger::logInfo("Failed to turn light on got exit code: " + std::to_string(exit_code));
        return;
    }

    rapidjson::Document d;
    d.Parse(output.c_str());
    rapidjson::Value& light_state = d["light_state"];
    m_last_light_state = light_state.GetBool();
    
    
    if(exit_code != 0){
        ErrorLogger::logInfo("Failed to turn light on got exit code: " + std::to_string(exit_code));
    }
}

void LightingController::handleRequest(std::string requestURL){
    return;
}

const std::string LightingController::pluginName(){
    return "Lighting";
}
