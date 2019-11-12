#include "Schedual.h"

#include "../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../CoreModules.h"
#include "Scheduler.h"

Schedual::Schedual(
    std::shared_ptr<Scheduler> scheduler
) :
    m_start_time(std::chrono::system_clock::time_point()),
    m_duration(0) {
        m_scheduler = scheduler;
}

Schedual::~Schedual(){
}


void Schedual::Disable(){
    m_enabled = false;
}

void Schedual::Enable(std::vector<int> days){
    m_enabled = true;

    if(days.size() == 0 ) {
        ErrorLogger::logError("Schedual created with no days enabled");
        return; 
    }
    m_enabled_days = days;

    if( m_start_time.time_since_epoch().count() ==0 ||
        m_duration.count() == 0 ||
        !m_callback ){
        ErrorLogger::logError("Failed to start schedual, its not been configured yet");
    }

    auto next_execution_time = m_start_time + m_duration;
    ScheduleNextInstance(
            next_execution_time
    );


}

void Schedual::Initialise(
            std::chrono::minutes duration,
            std::chrono::system_clock::time_point start_time,
            std::function<void ()> callback
){
    m_duration = duration;
    m_start_time = start_time;
    
    m_callback = [callback, this](){
        ScheduleNextInstance(
            std::chrono::system_clock::now() + m_duration
        );
        callback();
    };
}

bool Schedual::EnabledForDay(
    std::chrono::system_clock::time_point when
) {

    time_t tt = std::chrono::system_clock::to_time_t(when);
    tm local_tm = *localtime(&tt);

    auto it = std::find(m_enabled_days.begin(), 
                m_enabled_days.end(),
                local_tm.tm_wday); // days since sunday

    return it != m_enabled_days.end();

}

void Schedual::ScheduleNextInstance(
        std::chrono::system_clock::time_point when
    ) {

        while(!EnabledForDay(when)){
            when += std::chrono::hours(24);
        }


        auto t = std::chrono::system_clock::to_time_t(when);
        std::string time = std::ctime(&t);
        ErrorLogger::logInfo("next schedual will run at : "+time);

        m_scheduler->ScheduleTask(
            std::shared_ptr<ScheduledTask>(new CallbackTask(
                m_callback,
                when
            ))
        );
}


