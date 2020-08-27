#pragma once

#include "../../Arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Arsehole/Framework/Plugin/Plugin.h"

#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"


class BevChanPlugin 
    : 
        public Plugin {
public:

    BevChanPlugin(CoreModules* cm);
    virtual ~BevChanPlugin();

    void handleRequest(std::string requestURL);
    const std::string pluginName();

private:

    void updateDatabaseWithNewReadings(
        std::shared_ptr<IHTTPUrlRouter::IConnection> connection
    );

    void getLatestReadings(
        std::shared_ptr<IHTTPUrlRouter::IConnection> connection
    );

};

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
    return new BevChanPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
    delete plugin;
    return true;
}
