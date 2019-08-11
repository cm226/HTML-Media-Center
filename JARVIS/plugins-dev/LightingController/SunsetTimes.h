#pragma once
#include <vector>

class SunsetTimes{

public:

    SunsetTimes();

    bool IsSunDown();

private:

    std::vector<int> m_sunset;
    std::vector<int> m_sunrise;
    

};