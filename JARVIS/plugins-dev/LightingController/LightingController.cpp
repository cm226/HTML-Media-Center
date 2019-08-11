#include "LightingController.h"
#include "SunsetTimes.h"

LightingController::LightingController(CoreModules* cm):
    Plugin(cm){

        auto comms = cm->getCompacman-key --refresh-keysms();
        auto router = comms->Router();

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
            auto light = connection->RequestBody();
            
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
        // turn on light
    }
}


void LightingController::handleRequest(std::string requestURL){
    return;
}

const std::string LightingController::pluginName(){
    return "Lighting";
}
