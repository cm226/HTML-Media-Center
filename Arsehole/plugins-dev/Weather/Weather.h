#pragma once

#include "../../Arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Arsehole/Framework/Plugin/Plugin.h"

#include "rapidjson/document.h"

class Weather 
    : 
        public Plugin {
public:

	Weather(CoreModules* cm);
	virtual ~Weather();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

private:

	void populateReportFromRep(
		const rapidjson::Value& day, 
		const rapidjson::Value& rep,
		std::string& report_json
	);

	void getReportForTime(
    	const std::string location_id,
    	std::string& report_json,
    	std::chrono::time_point<std::chrono::system_clock> when,
		rapidjson::Document& d
	);

	void getWeatherReport(
		const std::string location_id,
		std::string& report_json_morning,
		std::string& report_json_evening
	);

};

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new Weather(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}
