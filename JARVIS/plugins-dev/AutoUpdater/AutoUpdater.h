	#pragma once

#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "../../JARVIS/Framework/Plugin/Plugin.h"

#include <memory>
#include <thread>
#include <mutex>


class AutoUpdater 
    : 
        public Plugin {
public:

	AutoUpdater(CoreModules* cm);
	virtual ~AutoUpdater();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

private:
	bool CheckForUpdate();
	bool BuildUpdate();
	void Restart();

	std::unique_ptr<std::thread> m_build_thread;
	std::mutex m_build_mutex;

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
