#include <string>

#include <boost/signals2.hpp>

#include "../Comms/HTTPServer/IHTTPUrlRouter.h"

class MotionSensor{

    public:
        MotionSensor(
            std::string name,
            IHTTPUrlRouter* router
        );

    public:
        boost::signals2::signal<void ()> sig_motion;

    private:
        std::string m_name;


};