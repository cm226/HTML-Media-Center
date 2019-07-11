#include <Vector>

class SunsetTimes{

public:

    SunsetTimes();

    static bool IsSunDown();

private:

    std::vector<int> m_sunset;
    std::vector<int> m_sunrise;
    

};