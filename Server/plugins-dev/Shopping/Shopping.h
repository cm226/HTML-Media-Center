	#pragma once

#include "../../Server/Framework/Plugin/IPluginDLLFactory.h"
#include "../../Server/Framework/Plugin/Plugin.h"

#include "../../ServerCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"

#include <boost/property_tree/ptree.hpp>


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


	void AddMeal(
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection
	);

	void GetIngredsFromJSON(
    	std::shared_ptr<std::vector<std::string>> sains_ingreds,
    	std::shared_ptr<std::vector<std::string>> aldi_ingreds,
    	boost::property_tree::ptree root
	);

	bool InsertAllIngredsFromJson(
    	std::shared_ptr<std::vector<std::string>> sains_ingreds,
    	std::shared_ptr<std::vector<std::string>> aldi_ingreds,
    	std::string meal_name
	);

	void EditMeal(
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
