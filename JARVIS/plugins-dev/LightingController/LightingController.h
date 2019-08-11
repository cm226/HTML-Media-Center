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
};