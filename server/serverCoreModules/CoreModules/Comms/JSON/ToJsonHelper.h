#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


namespace Comms{

namespace JSON {

class ToJsonHelper{

public:

    template<typename... Vals>
    std::string ToJson(
        std::vector<std::string> names,
        Vals... vals
    ){

        std::stringstream ss;

        // flip the order of the names so that the order passed in the interface 
        // is intuitive
        std::reverse(names.begin(),names.end());

        ss<< "{";
        ToJson_i(names, ss, vals...);
        ss<<"}";

        return ss.str();
    }

private:

    template<typename T>
    void ToJson_i(
        std::vector<std::string> names,
        std::stringstream& ss,
        T val) {

        ss<< "\"" << names.back() << "\"" <<
            ":"  << "\"" << ToString(val) << "\"";
    }


    template<typename T, typename... Vals>
    void ToJson_i(
        std::vector<std::string> names,
        std::stringstream& ss,
        T val,
        Vals... vals) {
        
            ToJson_i(names, ss, val);
            names.pop_back();
            ss << ",";

            ToJson_i(names, ss, vals...);  
        }

    std::string ToString(std::string s){
        return s;
    }

    template<typename T>
    std::string ToString(T s){
        return std::to_string(s);
    }
};

}
}