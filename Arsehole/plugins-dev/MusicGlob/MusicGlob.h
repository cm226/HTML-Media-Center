#pragma once

#include "../../arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../arsehole/Framework/Plugin/Plugin.h"


class MusicGlobPlugin 
    : 
        public Plugin {
public:

	MusicGlobPlugin(CoreModules* cm);
	virtual ~MusicGlobPlugin();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

};


DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new MusicGlobPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}

