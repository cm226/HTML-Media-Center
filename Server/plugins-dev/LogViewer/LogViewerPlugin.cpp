#include "LogViewerPlugin.h"
#include "../../ServerCoreModules/CoreModules/config.h"

#include "../../ServerCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"

#include <sstream>

LogViewerPlugin::LogViewerPlugin(CoreModules* cm): Plugin(cm), name("LogViewer")
{
	this->logParser.setLogFileLocation(
		Config::GetInstance()->LogLocation()+
		std::string("/log.log"));

	auto comms = cm->getComms();
    auto router = comms->Router();

	router->RegisterWidgit("plugins/LogViewer_content");

    router->MapURLRequest(
        "/plugins/LogViewer/Entries",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
			auto params = connection->RequestParams();
			std::size_t num_entries = 50;
			if(params.find("size") != params.end()){
				num_entries = stoi(params["size"]);
			}
            connection->Write(entriesToJson(num_entries));
        }
    );     
}


LogViewerPlugin::~LogViewerPlugin(void)
{

}

std::string LogViewerPlugin::entriesToJson(std::size_t n){

	std::vector<model::LogEntry> entries;
	if(!logParser.getParsedEntries(entries, n)){
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
