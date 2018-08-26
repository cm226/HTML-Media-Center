#include "Shopping.h"
#include "../../JARVISCoreModules/CoreModules/Database/Querys/NoBullshitQuery.h"
#include "../../JARVISCoreModules/CoreModules/Database/Results/ResultTypes.h"
#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/HTTPServer.h"


ShoppingPlugin::ShoppingPlugin(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto server = comms->Server();

    auto db = cm->getDatabaseConnection();



    server->MapURLRequest(
        "/plugins/Shopping",
        [&](
            http::server<HTTPServer>::request,
            http::server<HTTPServer>::connection_ptr connection
        ){
            DatabaseTables::NoBullshitQuery query("\
                SELECT meal_name, ingredient_name, store\
                FROM Meals, Ingredients \
                WHERE Meals.id = Ingredients.id\
                GROUP BY Meals.meal_name");

            auto results = std::list<std::shared_ptr<ResultBase>>();

            std::function<std::shared_ptr<ResultBase>()> factory 
                = []()->std::shared_ptr<ResultBase>{

                auto test = std::shared_ptr<ResultBase>(
                    new ResultGroup<std::string>(
                        "Meal.name",
                        {
                            std::make_shared<ResultList<std::string>>("Ingredient.name"),
                            std::make_shared<ResultList<std::string>>("Ingredient.store")
                        }
                    ));

                return test;
            };
            

            this->coreMod->getDatabaseConnection()->runQuery(
                &query, 
                factory,
                results);



        }
    );

}

ShoppingPlugin::~ShoppingPlugin(){

}

void ShoppingPlugin::handleRequest(
    std::string requestURL
) {


}

const std::string ShoppingPlugin::pluginName(){
    return "Shopping";
}
