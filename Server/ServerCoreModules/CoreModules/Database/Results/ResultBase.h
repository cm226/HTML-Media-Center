#pragma once
#include "../ResultWrapper.h"

class ResultBase{

    public:
        virtual bool ReadNext(ResultWrapper& result) = 0;
};