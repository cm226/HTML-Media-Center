#include "GoogleSearch.h"
#include "../../config.h"
#include "../../CoreModules.h"

#include "rapidjson/document.h"

#include <boost/algorithm/string.hpp>

namespace Comms {

GoogleSearch::GoogleSearch(){

}

GoogleSearch::~GoogleSearch(){

}

std::vector<GoogleSearch::Result> GoogleSearch::Search(std::string term, CommsNS::IComms* comms){

    auto config = Config::GetInstance();

    boost::replace_all(term, " ", "%20");

    std::stringstream ss;
    ss<<"https://www.googleapis.com/customsearch/v1";
    ss<<"?key=" << config->GoogleSearchKey();
    ss<<"&cx=" <<config->GoogleSearchEngine();
    ss<<"&q=" << term;

    std::string search_result;
    CommsNS::IJSONRequest* req = comms->createJSONRequest();
	req->requestURL(ss.str());
	req->makeRequest(search_result);

    rapidjson::Document d;
    d.Parse(search_result.c_str());

    std::vector<GoogleSearch::Result> res_vec;
    auto& results = d["items"];
    for (rapidjson::Value::ConstValueIterator itr = results.Begin(); itr != results.End(); ++itr) {
        auto& result = *itr;

        GoogleSearch::Result r;

        // validate that the result has the fields we expect
        if(!result.HasMember("title") ||
            !result.HasMember("link") ||
            !result.HasMember("pagemap")){
                ErrorLogger::logError("google search result unexpected format");
                continue;
            }

        r.title = result["title"].GetString();
        r.url = result["link"].GetString();

        auto& pagemap = result["pagemap"];
        auto& thumbs = pagemap["cse_thumbnail"];
        // this type is an array in the results not sure why but just grab the first one. 
        auto& thumb =    *thumbs.Begin();

        r.thumb_url = thumb["src"].GetString();
        r.thumb_size = std::make_pair<int, int>(
            std::stoi(thumb["width"].GetString()),
            std::stoi(thumb["height"].GetString())
        );

        res_vec.push_back(r);

    }

    return res_vec;

    
}
    
}