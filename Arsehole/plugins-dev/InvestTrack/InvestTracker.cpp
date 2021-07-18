#include "InvestTracker.h"

#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../ArseholeCoreModules/CoreModules/config.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <stdlib.h> 
#include <fstream>
#include <cstdlib>


InvestTracker::InvestTracker(
    CoreModules* cm
):
    Plugin(cm)
{
    
    auto comms = cm->getComms();
    auto router = comms->Router();

    router->RegisterWidgit("plugins/Invest_content");

    router->MapURLRequest("/plugins/Invest/getData",[&](
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection 
    ){

    });

    
 }

InvestTracker::~InvestTracker()
{
}


void InvestTracker::handleRequest(
    std::string requestURL
) {
}

const std::string InvestTracker::pluginName(){
    return "Invest";
}
