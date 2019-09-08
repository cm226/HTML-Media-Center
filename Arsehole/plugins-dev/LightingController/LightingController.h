#pragma once

#include "../../arseholeCoreModules/CoreModules/CoreModules.h"
#include "../../arsehole/Framework/Plugin/Plugin.h"

class LightingController : public Plugin {

    public:
        LightingController(CoreModules* cm);

        void handleRequest(std::string requestURL);
	    virtual const std::string pluginName();

    private:
        void bedroomMotion();
        void turnOnLight(
            std::string name
        );
        void turnOffLight(
            std::string name
        );

        void parseNodeOutput(
            std::string output
        );

    private:
        bool m_sleeping;
        std::chrono::time_point<std::chrono::system_clock> m_sleeping_at;
        bool m_last_light_state;
        std::string m_lighting_dir;
};