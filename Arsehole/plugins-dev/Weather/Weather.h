#pragma once

#include "../../Arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Arsehole/Framework/Plugin/Plugin.h"

class Weather 
    : 
        public Plugin {
public:

	Weather(CoreModules* cm);
	virtual ~Weather();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

private:

	void getWeatherReport(
		const std::string location_id,
		std::string& report_json
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
