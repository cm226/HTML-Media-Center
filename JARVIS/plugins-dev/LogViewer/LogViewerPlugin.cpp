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

void LogViewerPlugin::renderErrorEntry(model::LogEntry& entry, ElementList* elementList)
{
	htmlrendere::elements::DockingLayout* logEntry = new htmlrendere::elements::DockingLayout("entry");
	logEntry->addStyle("background-color","rgba(255,0,0,0.5)");

	Lable* entryTime = new Lable("entryTime");
	Lable* entrySeverity = new Lable("entrySeverity");
	Lable* entryMessage = new Lable("entryMessage");

	std::stringstream timeStringStream;
	timeStringStream << entry.logTimeStamp().date() << " " << entry.logTimeStamp().time_of_day();
	entryTime->setText(timeStringStream.str());
	entrySeverity->setText(entry.getSeverityStr());
	entryMessage->setText(entry.getMessage());

	logEntry->dockRight(entryTime,30);
	logEntry->dockTop(entrySeverity,40);
	logEntry->dockBottom(entryMessage, 60);

	elementList->addElement(logEntry);
}
void LogViewerPlugin::renderWarnEntry(model::LogEntry& entry, ElementList* elementList)
{
	htmlrendere::elements::DockingLayout* logEntry = new htmlrendere::elements::DockingLayout("entry");


	Lable* entryTime = new Lable("entryTime");
	Lable* entrySeverity = new Lable("entrySeverity");
	Lable* entryMessage = new Lable("entryMessage");

	std::stringstream timeStringStream;
	timeStringStream << entry.logTimeStamp().date() << " " << entry.logTimeStamp().time_of_day();
	entryTime->setText(timeStringStream.str());
	entrySeverity->setText(entry.getSeverityStr());
	entryMessage->setText(entry.getMessage());

	logEntry->dockRight(entryTime,30);
	logEntry->dockTop(entrySeverity,40);
	logEntry->dockBottom(entryMessage, 60);

	elementList->addElement(logEntry);
}
void LogViewerPlugin::renderInfoEntry(model::LogEntry& entry, ElementList* elementList)
{
	htmlrendere::elements::DockingLayout* logEntry = new htmlrendere::elements::DockingLayout("entry");


	Lable* entryTime = new Lable("entryTime");
	Lable* entrySeverity = new Lable("entrySeverity");
	Lable* entryMessage = new Lable("entryMessage");

	std::stringstream timeStringStream;
	timeStringStream << entry.logTimeStamp().date() << " " << entry.logTimeStamp().time_of_day();
	entryTime->setText(timeStringStream.str());
	entrySeverity->setText(entry.getSeverityStr());
	entryMessage->setText(entry.getMessage());

	logEntry->dockRight(entryTime,30);
	logEntry->dockTop(entrySeverity,40);
	logEntry->dockBottom(entryMessage, 60);

	elementList->addElement(logEntry);
}

void LogViewerPlugin::renderEntry(model::LogEntry& entry, ElementList* elementList)
{
	
	switch(entry.getSeverity())
	{
		case(model::LogEntry::ERROR):
			this->renderErrorEntry(entry,elementList);
			break;
		case(model::LogEntry::INFO):
			this->renderInfoEntry(entry,elementList);
			break;
		case(model::LogEntry::WAR):
			this->renderWarnEntry(entry,elementList);
			break;
	}
}