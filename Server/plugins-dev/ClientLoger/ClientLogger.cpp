#include "ClientLogger.h"

#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../ServerCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../ServerCoreModules/CoreModules/config.h"

#include <stdlib.h> 
#include <fstream>
#include <cstdlib>


ClientLogger::ClientLogger(
    CoreModules* cm
):
    Plugin(cm)
{
    
    auto comms = cm->getComms();
    auto router = comms->Router();

    router->MapURLRequest(
        "/plugins/ClientLogger/logError",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            ErrorLogger::logError(connection->RequestBody());
        }
    );    
}

ClientLogger::~ClientLogger()
{
}


void ClientLogger::handleRequest(
    std::string requestURL
) {
}

const std::string ClientLogger::pluginName(){
    return "ClientLogger";
}
