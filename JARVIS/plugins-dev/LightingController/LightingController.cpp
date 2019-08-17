#include "LightingController.h"
#include "SunsetTimes.h"

LightingController::LightingController(CoreModules* cm):
    Plugin(cm),
    m_sleeping(false){

        auto comms = cm->getComms();
        auto router = comms->Router();

        router->RegisterWidgit("/plugins/Lighting_content/widgit.html");

        router->MapURLRequest(
            "/plugins/Lighting/AllLights",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            connection->Write("Bedroom");
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
        });

        router->MapURLRequest(
            "/plugins/Lighting/TurnOffLight",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto params = connection->RequestParams();
            auto light = params["name"];
            turnOffLight(light);
            
        });

        router->MapURLRequest(
            "/plugins/Lighting/Sleeping",
            [&](
                std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            m_sleeping_at = std::chrono::system_clock::now();
            m_sleeping = true;
            ErrorLogger::logInfo("Sleeping Set");
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
            ErrorLogger::logInfo("Failed to turn light on got exit code: " +exit_code);
        }

    } else{
        ErrorLogger::logInfo("Attempted to turn on light but sleeping is set");
    }
}

void LightingController::turnOffLight(
    std::string name
){
    bool exit_code = 0;
    this->coreMod->getTaskList().RunSystemCommand(
        "node ControlLighting light="+name+" state=off",
        exit_code);
    
    if(exit_code != 0){
        ErrorLogger::logInfo("Failed to turn light on got exit code: " +exit_code);
    }
}

void LightingController::handleRequest(std::string requestURL){
    return;
}

const std::string LightingController::pluginName(){
    return "Lighting";
}
