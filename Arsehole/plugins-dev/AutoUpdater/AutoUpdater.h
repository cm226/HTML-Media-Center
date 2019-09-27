	#pragma once

#include "../../Arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Arsehole/Framework/Plugin/Plugin.h"

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>


class AutoUpdater 
    : 
        public Plugin {
public:

	AutoUpdater(CoreModules* cm);
	virtual ~AutoUpdater();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

private:
	bool CheckForUpdate(std::string& output);
	bool BuildUpdate();
	void Restart();

	std::unique_ptr<std::thread> m_build_thread;
	std::mutex m_build_mutex;

	std::mutex m_build_stage_changed;
	std::condition_variable m_build_stage_cv;

	std::string m_stage;
	std::string m_sentStage; // last stage sent to client

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
