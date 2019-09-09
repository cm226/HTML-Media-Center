	#pragma once

#include "../../Arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Arsehole/Framework/Plugin/Plugin.h"


class ClientLogger 
    : 
        public Plugin {
public:

	ClientLogger(CoreModules* cm);
	virtual ~ClientLogger();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

private:


};

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new ClientLogger(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}
