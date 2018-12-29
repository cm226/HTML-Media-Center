#pragma once

#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "../../JARVIS/Framework/Plugin/Plugin.h"

#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"


class ShoppingPlugin 
    : 
        public Plugin {
public:

	ShoppingPlugin(CoreModules* cm);
	virtual ~ShoppingPlugin();

	void handleRequest(std::string requestURL);
	const std::string pluginName();

private:

	std::string resultsToString(
		ResultWrapper& results
	);

	void processSelectedMessages(
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection
	);

};



DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new ShoppingPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}
