#pragma once

#include "../../JARVISCoreModules/CoreModules/CoreModules.h"
#include "../../JARVIS/Framework/Plugin/Plugin.h"

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

    private:
        bool m_sleeping;
        std::chrono::time_point<std::chrono::system_clock> m_sleeping_at;
};