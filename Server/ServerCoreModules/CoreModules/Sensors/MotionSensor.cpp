#include "MotionSensor.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"

MotionSensor::MotionSensor(
    std::string name,
    IHTTPUrlRouter* router
) {
    m_name = name;
    m_router = router;
    m_url_handler = [&](
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection 
    ){
        ErrorLogger::logInfo("motion detected from :" + m_name);
        // lets just assume all messages from motion sensors are motion...
        for(auto& handler : m_sig_motion){
            handler();
        }
    };

    m_router->MapURLRequest("/Sensors/"+name, m_url_handler);
}


void MotionSensor::Motion(std::function<void ()> handler){
    m_sig_motion.push_back(handler);
}


