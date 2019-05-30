#include "LogViewerPlugin.h"
#include "../../JARVISCoreModules/CoreModules/config.h"

#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"

#include <sstream>

LogViewerPlugin::LogViewerPlugin(CoreModules* cm): Plugin(cm), name("LogViewer")
{
	this->logParser.setLogFileLocation(
		Config::GetInstance()->LogLocation()+
		std::string("\\log.log"));

	auto comms = cm->getComms();
    auto router = comms->Router();

    router->MapURLRequest(
        "/plugins/LogViewer/Entries",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            connection->Write(entriesToJson());
        }
    );     
}


LogViewerPlugin::~LogViewerPlugin(void)
{

}

std::string LogViewerPlugin::entriesToJson(){

	std::vector<model::LogEntry> entries;
	if(!logParser.getAllEntrys(entries)){
		ErrorLogger::logError("Failed to get error log entries");
	}

	std::stringstream ss;
	ss<<"[";
	bool first = true;
	for(auto& entry : entries){
		if(!first){ss<<",";}
		first = false;
		ss << "{" 
		<< "\"msg\":\"" << entry.getMessage() << "\","
		<< "\"ts\":\"" << to_simple_string(entry.logTimeStamp()) << "\","
		<< "\"sev\":\"" << entry.getSeverityStr() << "\""
		<< "}"; 
	}

	ss<<"]";

	return ss.str();
}

void LogViewerPlugin::handleRequest(std::string requestURL){
	return;
}

const std::string LogViewerPlugin::pluginName()
{
	return this->name;
}
