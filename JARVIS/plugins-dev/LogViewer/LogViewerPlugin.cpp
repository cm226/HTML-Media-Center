#include "LogViewerPlugin.h"
#include "../../JARVISCoreModules/CoreModules/config.h"

#include <sstream>

LogViewerPlugin::LogViewerPlugin(CoreModules* cm): Plugin(cm), name("LogViewer")
{
	this->logParser.setLogFileLocation(LOG_LOCATION+std::string("\\log.log"));

	auto comms = cm->getComms();
    auto router = comms->Router();

    router->MapURLRequest(
        "/plugins/LogViewer/entries",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            connection->write(entriesToJson());
        }
    );    
}


LogViewerPlugin::~LogViewerPlugin(void)
{

}

std::string LogViewerPlugin::entriesToJson(){

	std::priority_queue<model::LogEntry> entries;
	if(!logParser->getAllEntrys(entries)){
		ErrorLogger::logError("Failed to get error log entries");
	}

	std::string_stream ss;
	ss<<"[";
	first = true;
	for(auto& entry : entries){
		if(!first){ss<<","}
		first = false;
		ss << "{" 
		<< "msg:" << entry.getMessage()
		<< "ts:" << to_simple_string(entry.logTimeStamp())
		<< "sev:" << entry.getSeverityStr()
		<< "}"; 
	}

	ss<<"]";

	return ss.str();
}


bool LogViewerPlugin::whatDoYouLookLike(Page* page)
{
	return true;
}

const char* LogViewerPlugin::pluginName()
{
	return this->name.c_str();
}
