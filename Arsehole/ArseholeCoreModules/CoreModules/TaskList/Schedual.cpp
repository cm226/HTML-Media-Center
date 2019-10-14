#include "Schedual.h"

#include "../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../CoreModules.h"
#include "Scheduler.h"

Schedual::Schedual(
    std::shared_ptr<Scheduler> scheduler
) :
    m_start_time(0),
    m_duration(0) {
        m_scheduler = scheduler;
}

Schedual::~Schedual(){



Schedual::Disable(){
    m_enabled = false;
}

Schedual::Enable(){
    m_enabled = true;

    if( m_start_time ==0 ||
        m_duration == 0 ||
        !m_callback ){
        ErrorLogger::logError("Failed to start schedual, its not been configured yet")
    }

    auto next_execution_time = m_start_time + m_duration;
    ScheduleNextInstance(next_execution_time);


}

void Schedual::SetFrequency(
            std::chrono::duration duration,
            std::chrono::system_clock::timepoint start_time
){
    m_duration = duration;
    m_start_time = start_time;
    
}

void Schedual::ScheduleNextInstance(
    std::chrono::duration when
){

    m_scheduler->ScheduleTask(
            CallbackTask(
                m_callback,
                std::chrono::system_clock::now() + when
            )
    );
}

void Schedual::SetCallback(
    std::function<void ()> callback
) {
    m_callback = [callback, &this](){
        ScheduleNextInstance(
            std::chrono::system_clock::now() + m_duration
        );
        callback();
    };
}

