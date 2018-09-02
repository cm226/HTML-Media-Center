#include "Shopping.h"
#include "../../JARVISCoreModules/CoreModules/Database/Querys/NoBullshitQuery.h"
#include "../../JARVISCoreModules/CoreModules/Database/Results/ResultTypes.h"
#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/HTTPServer.h"

extern const char meal_name_col[] = "Meal.name";
extern const char ingred_name_col[] = "Ingredient.name";
extern const char ingred_store_col[] = "Ingredient.store";

ShoppingPlugin::ShoppingPlugin(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto router = comms->Router();

    auto db = cm->getDatabaseConnection();



    router->MapURLRequest(
        "/plugins/Shopping",
        [&](
            boost::network::http::server<HTTPServer>::request,
            boost::network::http::server<HTTPServer>::connection_ptr connection
        ){
            DatabaseTables::NoBullshitQuery query("\
                SELECT meal_name, ingredient_name, store\
                FROM Meals, Ingredients \
                WHERE Meals.id = Ingredients.id\
                GROUP BY Meals.meal_name");
                
            ResultWrapper result_wrapper;
            this->coreMod->getDatabaseConnection()->runQuery(
                &query, 
                result_wrapper);

            auto results = Results<
                            ResultGroup<
                                std::string,
                                meal_name_col,
                                ResultList<std::string, ingred_name_col>,
                                ResultList<std::string, ingred_store_col>
                            >
                        >(result_wrapper);            

            std::stringstream results_json;
            results_json << "{ meals : [";

            for(auto& meal : results ){

                results_json << "{'meal':'" << meal->Value();

                auto ingreds_name = std::get<0>(meal->Children());
                auto ingreds_store = std::get<1>(meal->Children());

                results_json << "', 'ingredients':[";
                for(auto& ingred_name : ingreds_name.Values()){
                    results_json << "'" << ingred_name << "', ";
                }
            }

            results_json<<"]}";
            connection->write(results_json.str());

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
