#pragma once

#include "../../ArseholeCoreModules/CoreModules/CoreModules.h"
#include "../../Arsehole/Framework/Plugin/Plugin.h"

#include <mutex>

class Schedual;

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

        bool parseNodeOutput(
            std::string output,
            bool expected_state
        );

        bool trySetLightState(
            bool state
        );

        void setupSchedule();

    private:
        bool m_sleeping;
        std::chrono::time_point<std::chrono::system_clock> m_sleeping_at;
        bool m_last_light_state;
        std::string m_lighting_dir;
        std::shared_ptr<Schedual> m_schedual;

        // only have 1 node command in flight at once
        std::mutex m_node_mutex;
};