#pragma once

#include "../../Server/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Server/Framework/Plugin/Plugin.h"

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>


class ConfigEditor 
    : 
        public Plugin {
public:

	ConfigEditor(CoreModules* cm);
	virtual ~ConfigEditor();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

private:
	
};

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new ConfigEditor(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}
