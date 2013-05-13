

#pragma once
#ifndef _LOG_VIEWER_PLUGIN
#define _LOG_VIEWER_PLUGIN

#include "../../JARVISCoreModules/CoreModules/CoreModules.h"
#include "../../JARVIS/Framework/Plugin/Plugin.h"
#include "LogEntryParser.h"
#include <string>

class LogViewerPlugin : public Plugin
{
private:
	std::string name;
	LogEntryParser logParser;

	void renderEntry(model::LogEntry& entry, ElementList* elementList);

	void renderErrorEntry(model::LogEntry& entry, ElementList* elementList);
	void renderWarnEntry(model::LogEntry& entry, ElementList* elementList);
	void renderInfoEntry(model::LogEntry& entry, ElementList* elementList);

public:
	LogViewerPlugin(CoreModules* cm);
	virtual ~LogViewerPlugin(void);

	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
};

#endif