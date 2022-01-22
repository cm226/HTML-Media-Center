#include <string>

#include <boost/signals2.hpp>

#include "../Comms/HTTPServer/IHTTPUrlRouter.h"

class MotionSensor{

    public:
        MotionSensor(
            std::string name,
            IHTTPUrlRouter* router
        );

        ~MotionSensor();

    public:

        void Motion(std::function<void ()> handler);
        

    private:
        std::vector<std::function<void ()>> m_sig_motion;
        std::string m_name;

        IHTTPUrlRouter::URLHandle m_url_handler;
        IHTTPUrlRouter* m_router;

};