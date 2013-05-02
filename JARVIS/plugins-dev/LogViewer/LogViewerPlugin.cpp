#include "LogViewerPlugin.h"
#include "../../JARVISCoreModules/CoreModules/config.h"

#include <sstream>

LogViewerPlugin::LogViewerPlugin(CoreModules* cm): Plugin(cm), name("LogViewer")
{
	this->logParser.setLogFileLocation(LOG_LOCATION+std::string("\\log.log"));
}


LogViewerPlugin::~LogViewerPlugin(void)
{

}


bool LogViewerPlugin::whatDoYouLookLike(Page* page)
{
	std::priority_queue<model::LogEntry> entrys;
	this->logParser.getAllEntrys(entrys);

	ElementList* logEntrys = new ElementList("logEntrys");
	while(!entrys.empty())
	{
		renderEntry(entrys.top(),logEntrys);
		entrys.pop();
	}
	page->addElement(logEntrys);
	return true;
}

const char* LogViewerPlugin::pluginName()
{
	return this->name.c_str();
}

void LogViewerPlugin::renderEntry(model::LogEntry& entry, ElementList* elementList)
{
	Lable* entryTime = new Lable("entryTime");
	Lable* entrySeverity = new Lable("entrySeverity");
	Lable* entryMessage = new Lable("entryMessage");

	std::stringstream timeStringStream;
	timeStringStream << entry.logTimeStamp().date() << " " << entry.logTimeStamp().time_of_day();
	entryTime->setText(timeStringStream.str());
	entrySeverity->setText(entry.getSeverityStr());
	entryMessage->setText(entry.getMessage());

	elementList->addElement(entryTime);
	elementList->addElement(entrySeverity);
	elementList->addElement(entryMessage);
}