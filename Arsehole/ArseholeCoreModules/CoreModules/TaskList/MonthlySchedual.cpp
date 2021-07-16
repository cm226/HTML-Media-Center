#include "MonthlySchedual.h"


MonthlySchedual::MonthlySchedual(
    std::shared_ptr<Scheduler> scheduler
) :
Schedual(scheduler) {

}

MonthlySchedual::~MonthlySchedual(){

}

void MonthlySchedual::Initialse(
    std::function<void ()> callback
) {
    std::time_t t = std::time(nullptr);
    std::tm* tm = std::localtime(&t);

    auto tp = std::chrono::system_clock::from_time_t(
        std::mktime(tm)
    );

    // kinda roughly a month...
    Schedual::Initialise(
        std::chrono::hours(24 * 30),
        tp,
        callback
    );

    Enable({1,2,3,4,5});

}