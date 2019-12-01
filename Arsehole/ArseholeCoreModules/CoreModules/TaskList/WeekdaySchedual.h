#pragma once

#include "Schedual.h"

class Scheduler;

class WeekdaySchedual
: Schedual {

public:

    WeekdaySchedual(
        std::shared_ptr<Scheduler> scheduler
    );
    virtual ~WeekdaySchedual();


    void Initialse(
        int hour, 
        int min,
        std::function<void ()> callback 
    );

};