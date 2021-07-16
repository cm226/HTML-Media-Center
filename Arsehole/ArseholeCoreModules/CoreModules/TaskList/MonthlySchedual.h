#pragma once

#include "Schedual.h"

class MonthlySchedual
: Schedual {

public:

    MonthlySchedual(
        std::shared_ptr<Scheduler> scheduler
    );
    virtual ~MonthlySchedual();


    void Initialse(
        std::function<void ()> callback 
    );

};