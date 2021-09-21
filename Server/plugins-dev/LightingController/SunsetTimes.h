#pragma once
#include <vector>

class SunsetTimes{

public:

    SunsetTimes();

    bool IsSunDown();
    int nextSunSet();

private:

    std::vector<int> m_sunset;
    std::vector<int> m_sunrise;
    

};