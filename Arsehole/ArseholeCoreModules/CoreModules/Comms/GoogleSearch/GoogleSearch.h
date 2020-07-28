#include <string.h>
#include "../JSON/PodToJSONBase.h"

#include "../IComms.h"

namespace Comms{

class GoogleSearch{

public:
    class Result : public Comms::JSON::PodToJsonBase<Result> {

    public:

        Result(){

        }

        std::string title;
        std::string url;
        std::string thumb_url;
        std::pair<int, int> thumb_size;

        std::string ToJson(){
            return Comms::JSON::PodToJsonBase<Result>::ToJson(
                this,
                {"title", "url", "thumb_url", "thumb_size"},
                &Result::title, 
                &Result::url,
                &Result::thumb_url,
                &Result::thumb_size
            );
        }
    };

    public:
        GoogleSearch();
        ~GoogleSearch();

    public:

        std::vector<Result> Search(std::string term, CommsNS::IComms* comms);

};

}