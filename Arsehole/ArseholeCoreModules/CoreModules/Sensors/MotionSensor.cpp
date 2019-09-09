#include "MotionSensor.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"

MotionSensor::MotionSensor(
    std::string name,
    IHTTPUrlRouter* router
) {
    m_name = name;
    router->MapURLRequest("/Sensors/"+name,
    [&](
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection 
    ){
        ErrorLogger::logInfo("motion detected from :" + m_name);
        // lets just assume all messages from motion sensors are motion...
        for(auto& handler : m_sig_motion){
            handler();
        }
    });
}

void MotionSensor::Motion(std::function<void ()> handler){
    m_sig_motion.push_back(handler);
}


