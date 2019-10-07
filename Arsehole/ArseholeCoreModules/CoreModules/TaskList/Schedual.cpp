#include "Schedual.h"

#include "../../../ErrorLogger/Errors/ErrorLogger.h"

Schedual::Schedual() :
    m_start_time(0),
    m_duration(0) {

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

}

Schedual::SetFrequency(
            std::chrono::duration duration,
            std::chrono::system_clock::timepoint start_time
){
    m_duration = duration;
    m_start_time = start_time;
    
}

Schedual::SetCallback(
    std::function<void ()> callback
) {
    m_callback = callback;
}

