#pragma once

#include "ExpiringModel.h"

#include "../../ServerCoreModules/CoreModules/CoreModules.h"
#include "../../Server/Framework/Plugin/Plugin.h"
#include "../../ErrorLogger/Errors/LoggerModel.h"

#include <mutex>

class WeekdaySchedual;

class LightingController : public Plugin {

    public:
        LightingController(CoreModules* cm);

        void handleRequest(std::string requestURL);
	    virtual const std::string pluginName();

    private:
        void bedroomMotion();
        void turnOnLight(
            std::string name,
            int brightness
        );
        void turnOffLight(
            std::string name
        );

        bool trySetLightState(
            bool state,
            int brightness
        );

        void setupSchedule();

        std::string statusToJson();

    private:
        LoggerModel<bool> m_last_light_state;
        ExpiringModel<LoggerModel<int>> m_last_brightness_state;
        ExpiringModel<LoggerModel<bool>> m_sleeping;

        std::shared_ptr<WeekdaySchedual> m_schedual;
        
        // lights turn off after 5 min of no motion
        std::shared_ptr<CallbackTask> m_turn_off_light_task;

        // only have 1 node command in flight at once
        std::mutex m_node_mutex;

        const std::string m_lights[2] = {"192.168.1.137", "192.168.1.197"};
};