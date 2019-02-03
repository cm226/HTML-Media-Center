	#pragma once

#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "../../JARVIS/Framework/Plugin/Plugin.h"



class AutoUpdater 
    : 
        public Plugin {
public:

	AutoUpdater(CoreModules* cm);
	virtual ~AutoUpdater();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

};

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new AutoUpdater(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}
