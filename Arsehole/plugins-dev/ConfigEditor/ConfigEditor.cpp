#include "ConfigEditor.h"

#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../ArseholeCoreModules/CoreModules/config.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/JSON/ToJsonHelper.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <stdlib.h> 
#include <fstream>
#include <cstdlib>


ConfigEditor::ConfigEditor(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto router = comms->Router();
    
    router->RegisterWidgit("plugins/ConfigEditor_content");

        router->MapURLRequest(
        "/plugins/ConfigEditor/get",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            Comms::JSON::ToJsonHelper jsonHelper;
            auto jsonStr = jsonHelper.ToJson(
                {"DBName", "DBPW", "DBUser", "MetOfficeKey"},
                Config::GetInstance()->DBName(),
                Config::GetInstance()->DBPw(),
                Config::GetInstance()->DBUser(),
                Config::GetInstance()->MetOfficeAPIKey()
            );

            connection->Write(jsonStr);
        }
    ); 

    router->MapURLRequest(
        "/plugins/ConfigEditor/set",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto config_str = connection->RequestBody();
             // parse JSON with property tree
            namespace pt = boost::property_tree;

            // Create a root
            pt::ptree root;

            std::stringstream config_json(config_str);
            // Load the json file in this ptree
            pt::read_json(config_json, root);

            auto dbName = root.get<std::string>("DBName");
            auto dbPW = root.get<std::string>("DBPW");
            auto dbUser = root.get<std::string>("DBUser");
            auto metKey = root.get<std::string>("MetOfficeKey");

            auto config = Config::GetInstance(); 
            config->DBName(dbName);
            config->DBUser(dbUser);
            config->DBPw(dbPW);
            config->MetOfficeAPIKey(metKey);
            config->WriteConfig();

            

        });  

}

ConfigEditor::~ConfigEditor()
{
}

void ConfigEditor::handleRequest(
    std::string requestURL
) {
}

const std::string ConfigEditor::pluginName(){
    return "ConfigEditor";
}
