#include "Weather.h"

#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../ArseholeCoreModules/CoreModules/config.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <stdlib.h> 
#include <fstream>
#include <cstdlib>


Weather::Weather(
    CoreModules* cm
):
    Plugin(cm)
{
    
    auto comms = cm->getComms();
    auto router = comms->Router();

    router->RegisterWidgit("plugins/Weather_content");

    router->MapURLRequest("/plugins/Weather/getReport",[&](
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection 
    ){

        const std::string location_gilmerton = "351572";
        const std::string location_leith = "322440";

        std::string g_report, l_report;
        getWeatherReport(location_gilmerton, g_report);
        getWeatherReport(location_leith, l_report);


        connection->Write("{\"Gilmerton\" : "+g_report+", \"Leith\" : "+l_report+" }");

    });

    
 }

Weather::~Weather()
{
}

void Weather::getWeatherReport(
    const std::string location_id,
    std::string& report_json
){

    std::string url = "http://datapoint.metoffice.gov.uk/public/data/val/wxfcs/all/json/";
    std::string get_params = "?res=3hourly&key=" + Config::GetInstance()->MetOfficeAPIKey();

    std::string weather;
    CommsNS::IJSONRequest* req = this->coreMod->getComms()->createJSONRequest();
    std::string full_url = url + location_id + get_params;
	req->requestURL(full_url);
	req->makeRequest(weather);

    rapidjson::Document d;
    d.Parse(weather.c_str());

    // is it past 8AM? if so then show tomorows forcast
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);

    if(local_tm.tm_hour > 8){
        
    }
    
    for(auto& day : d["SiteRep"]["DV"]["Location"]["Period"]) {
        for(auto& rep : day["Rep"][0]) {

            int min_past_midnight = std::stoi (rep["$"].GetString());
            if(min_past_midnight >= 480)
        }
    }



    auto& current_forecast = d["SiteRep"]["DV"]["Location"]["Period"][0]["Rep"][0];
    auto wind_speed = current_forecast["S"].GetString();
    auto feels_like_temp = current_forecast["F"].GetString();
    auto weather_type = current_forecast["W"].GetString();

    
    rapidjson::Document report;
    report.SetObject();

    rapidjson::Value ws;
    ws.SetString(rapidjson::StringRef(wind_speed));

    rapidjson::Value fl_tmp;
    fl_tmp.SetString(rapidjson::StringRef(feels_like_temp));

    rapidjson::Value wt;
    wt.SetString(rapidjson::StringRef(weather_type));

    report.AddMember("Wind_speed", ws, report.GetAllocator());
    report.AddMember("Feels_like", fl_tmp, report.GetAllocator());
    report.AddMember("Weather_type", wt, report.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    report.Accept(writer);

    report_json = buffer.GetString();
}


void Weather::handleRequest(
    std::string requestURL
) {
}

const std::string Weather::pluginName(){
    return "Weather";
}
