#pragma once

#include "../../Arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Arsehole/Framework/Plugin/Plugin.h"

#include "rapidjson/document.h"

class InvestTracker 
    : 
        public Plugin {
public:

	InvestTracker(CoreModules* cm);
	virtual ~InvestTracker();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

};

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new InvestTracker(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}
