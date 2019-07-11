#include "SunsetTimes.h"

#include <chrono>



bool SunsetTimes::IsSunDown(){

    std::chrono::system_clock::time_point now = 
        std::chrono::system_clock::now();

    time_t tt = std::chrono::system_clock::to_time_t(now);

    tm local_tm = *localtime(&tt);

    local_tm.tm_hour;


}