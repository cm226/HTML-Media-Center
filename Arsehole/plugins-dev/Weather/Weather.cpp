#include "Weather.h"

#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../ArseholeCoreModules/CoreModules/config.h"
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

        std::string g_report_morning, g_report_evening,
                    l_report_morning, l_report_evening;

        getWeatherReport(location_gilmerton, g_report_morning, g_report_evening);
        getWeatherReport(location_leith, l_report_morning, l_report_evening);


        connection->Write("{\"Gilmerton_morning\" : "+g_report_morning+
                          ",\"Gilmerton_evening\" : "+g_report_evening+
                          ",\"Leith_morning\" : "+l_report_morning+
                          ",\"Leith_evening\" : "+l_report_evening+" }");

    });

    
 }

Weather::~Weather()
{
}

void Weather::populateReportFromRep(
    const rapidjson::Value& day, 
    const rapidjson::Value& rep,
    std::string& report_json
) {

    auto wind_speed = rep["S"].GetString();
    auto gust_speed = rep["G"].GetString();
    auto feels_like_temp = rep["F"].GetString();
    auto weather_type = rep["W"].GetString();
    auto report_time_str = rep["$"].GetString();

    int report_time = std::stoi(report_time_str);
    
    rapidjson::Document report;
    report.SetObject();

    rapidjson::Value ws;
    ws.SetString(rapidjson::StringRef(wind_speed));

    rapidjson::Value gs;
    gs.SetString(rapidjson::StringRef(gust_speed));

    rapidjson::Value fl_tmp;
    fl_tmp.SetString(rapidjson::StringRef(feels_like_temp));

    rapidjson::Value wt;
    wt.SetString(rapidjson::StringRef(weather_type));

    report.AddMember("Wind_speed", ws, report.GetAllocator());
    report.AddMember("Gust_speed", gs, report.GetAllocator());
    report.AddMember("Feels_like", fl_tmp, report.GetAllocator());
    report.AddMember("Weather_type", wt, report.GetAllocator());
    report.AddMember("tr_start", report_time/60, report.GetAllocator());
    report.AddMember("tr_end", (report_time/60) + 3, report.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    report.Accept(writer);

    report_json = buffer.GetString();

}

void Weather::getReportForTime(
    const std::string location_id,
    std::string& report_json,
    std::chrono::time_point<std::chrono::system_clock> when,
    rapidjson::Document& d
) {

    auto& periods = d["SiteRep"]["DV"]["Location"]["Period"];
    for (rapidjson::Value::ConstValueIterator itr = periods.Begin(); itr != periods.End(); ++itr) {
        auto& day = *itr;
        
        std::tm tm;
        std::string date = day["value"].GetString(); 

        memset(&tm, 0, sizeof(std::tm));
        auto ret = strptime(date.c_str(), "%F", &tm);
        time_t t = mktime(&tm); 
            
        auto dayStart = std::chrono::system_clock::from_time_t(t);

        auto& rep = day["Rep"];
        for (rapidjson::Value::ConstValueIterator rep_it = rep.Begin(); rep_it != rep.End(); ++rep_it) {
    
            int min_past_midnight = std::stoi ((*rep_it)["$"].GetString());
            auto rep_time = dayStart + std::chrono::minutes(min_past_midnight);
        

            if(std::chrono::duration_cast<std::chrono::hours> (when - rep_time) < 
                std::chrono::hours(3))
            {
                populateReportFromRep(
                    day,
                    *rep_it,
                    report_json
                );
                return;
            }
        }

    }


}

void Weather::getWeatherReport(
    const std::string location_id,
    std::string& report_json_morning,
    std::string& report_json_evening
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

    // work out the time we want a forcast for
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);

    if(local_tm.tm_hour > 8) {
            now = now + std::chrono::hours(24);
            tt = std::chrono::system_clock::to_time_t(now);
            local_tm = *localtime(&tt);
    }

    // now set the target hour as 8AM. 
    local_tm.tm_hour = 8;

    time_t taregt_tt = std::mktime(&local_tm);
    auto target_time = std::chrono::system_clock::from_time_t(taregt_tt);

    getReportForTime(
        location_id,
        report_json_morning,
        target_time,
        d
    );

    // now set the target hour as 6PM. 
    local_tm.tm_hour = 18;

    taregt_tt = std::mktime(&local_tm);
    target_time = std::chrono::system_clock::from_time_t(taregt_tt);

    getReportForTime(
        location_id,
        report_json_evening,
        target_time,
        d
    );

}


void Weather::handleRequest(
    std::string requestURL
) {
}

const std::string Weather::pluginName(){
    return "Weather";
}
