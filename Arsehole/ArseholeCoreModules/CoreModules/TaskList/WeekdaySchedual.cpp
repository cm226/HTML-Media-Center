#include "WeekdaySchedual.h"


WeekdaySchedual::WeekdaySchedual(
    std::shared_ptr<Scheduler> scheduler
) :
Schedual(scheduler) {

}

WeekdaySchedual::~WeekdaySchedual(){

}

void WeekdaySchedual::Initialse(
    int hour, 
    int min,
    std::function<void ()> callback
) {
    std::time_t t = std::time(nullptr);
    std::tm* tm = std::localtime(&t);
    tm->tm_hour = hour;
    tm->tm_min = min;

    auto tp = std::chrono::system_clock::from_time_t(
        std::mktime(tm)
    );

    Schedual::Initialise(
        std::chrono::hours(24),
        tp,
        callback
    );

    Enable({1,2,3,4,5});

}