#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


namespace Comms{

namespace JSON {

template<typename TYPE>
class PodToJsonBase{

protected:

    template<typename... Args>
    std::string ToJson(
        TYPE* type,
        std::vector<std::string> names,
        Args... args
    ){

        std::stringstream ss;

        // flip the order of the names so that the order passed in the interface 
        // is intuitive
        std::reverse(names.begin(),names.end());

        ss<< "{";
        ToJson_i(type, names, ss, args...);
        ss<<"}";

        return ss.str();
    }

private:

    template<typename T>
    void ToJson_i(
        TYPE* type,
        std::vector<std::string> names,
        std::stringstream& ss,
        T TYPE::*mp) {

        ss<< "\"" << names.back() << "\"" <<
            ":"  << memberToString(type->*mp);
    }


    template<typename T, typename... Args>
    void ToJson_i(
        TYPE* type,
        std::vector<std::string> names,
        std::stringstream& ss,
        T TYPE::*mp,
        Args... args) {
        
            ToJson_i(type, names, ss, mp);
            names.pop_back();
            ss << ",";

            ToJson_i(type, names, ss, args...);  
        }

    
    

private:


    std::string memberToString(std::string m){
        std::stringstream ss;
        ss<<"\""<<m<<"\"";
        return ss.str();
    }

    std::string memberToString(std::pair<int, int> m) {

        std::stringstream ss;
        ss << "{ \"x\": " << m.first<<", \"y\" : "<<m.second<<"}";
        return ss.str();
    }




};

}
}