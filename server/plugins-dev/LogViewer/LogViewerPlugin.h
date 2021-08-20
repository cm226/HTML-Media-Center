

#pragma once
#ifndef _LOG_VIEWER_PLUGIN
#define _LOG_VIEWER_PLUGIN

#include "../../ServerCoreModules/CoreModules/CoreModules.h"
#include "../../Server/Framework/Plugin/Plugin.h"
#include "LogEntryParser.h"
#include <string>

class LogViewerPlugin : public Plugin
{
private:
	std::string name;
	LogEntryParser logParser;


	std::string entriesToJson(std::size_t n);

public:
	LogViewerPlugin(CoreModules* cm);
	virtual ~LogViewerPlugin(void);

	void handleRequest(std::string requestURL);

	virtual const std::string pluginName();
};

#endif
