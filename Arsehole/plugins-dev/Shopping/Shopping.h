	#pragma once

#include "../../arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "../../arsehole/Framework/Plugin/Plugin.h"

#include "../../arseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"


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
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection,
		bool allow_unselect
	);

	void processExtras(
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection
	);

	void getExtras(
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection
	);

	void setSelectedIngreds(
  	  	const std::vector<std::string>& selected_ingredients,
		bool allow_undet
	);

	void setSelectedMeals(
  	  	const std::vector<std::string>& selected_meals,
		bool allow_unset
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
