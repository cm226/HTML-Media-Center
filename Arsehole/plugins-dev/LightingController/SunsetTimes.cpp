#include "SunsetTimes.h"

#include <chrono>


SunsetTimes::SunsetTimes(){
    

    m_sunrise.push_back(9); // jan
    m_sunrise.push_back(8); // feb
    m_sunrise.push_back(7); // etc...
    m_sunrise.push_back(7);
    m_sunrise.push_back(5);
    m_sunrise.push_back(5);
    m_sunrise.push_back(5); // July
    m_sunrise.push_back(5);
    m_sunrise.push_back(6);
    m_sunrise.push_back(8);
    m_sunrise.push_back(8);
    m_sunrise.push_back(9);

    m_sunset.push_back(16); // Jan
    m_sunset.push_back(17); //Feb
    m_sunset.push_back(18); //Mar
    m_sunset.push_back(20); // apr
    m_sunset.push_back(21); // may
    m_sunset.push_back(22); //jun
    m_sunset.push_back(22); //july
    m_sunset.push_back(21); //aug
    m_sunset.push_back(20); //sep
    m_sunset.push_back(17); //oct
    m_sunset.push_back(16);// nov
    m_sunset.push_back(15);//dec


}

bool SunsetTimes::IsSunDown(){

    std::chrono::system_clock::time_point now = 
        std::chrono::system_clock::now();

    time_t tt = std::chrono::system_clock::to_time_t(now);

    tm local_tm = *localtime(&tt);

    auto sunset = m_sunset[local_tm.tm_mon];
    auto sunrise = m_sunrise[local_tm.tm_mon];

    if(local_tm.tm_hour >= sunset &&
       local_tm.tm_hour <= sunrise) {

           return true;
    }

    return false;
}

int SunsetTimes::nextSunSet(    
) {
    std::chrono::system_clock::time_point now = 
        std::chrono::system_clock::now();

    time_t tt = std::chrono::system_clock::to_time_t(now);

    tm local_tm = *localtime(&tt);

    return m_sunset[local_tm.tm_mon];
}