#include "Shopping.h"
#include "../../JARVISCoreModules/CoreModules/Database/Querys/NoBullshitQuery.h"
#include "../../JARVISCoreModules/CoreModules/Database/Results/ResultTypes.h"

#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"

extern const char meal_name_col[] = "meal_name";
extern const char ingred_name_col[] = "ingredient_name";
extern const char ingred_store_col[] = "store";

ShoppingPlugin::ShoppingPlugin(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto router = comms->Router();

    auto db = cm->getDatabaseConnection();



    router->MapURLRequest(
        "/plugins/ShoppingList",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            DatabaseTables::NoBullshitQuery query("\
                SELECT Meals.meal_name, Ingredients.ingredient_name, Ingredients.store\
                FROM Meals, Ingredients \
                WHERE Meals.id = Ingredients.meal_id\
                ORDER BY Meals.meal_name");
                
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
            results_json << "{ \"meals\" : {";

            bool first = true;
            for(auto& meal : results ){

                if(!first){
                    results_json << ",";
                }
                first = false;
                
                results_json << "\"" << meal->Value() << "\" : ";

                auto ingreds_name = std::get<0>(meal->Children());
                auto ingreds_store = std::get<1>(meal->Children());

                auto store_values = ingreds_store.Values();
                auto ingred_values = ingreds_name.Values();

                if(store_values.size() != 
                    ingred_values.size()){

                        ErrorLogger::logWarn("sad times, store and ingredient results not the same size");
                        return;
                }

                results_json << "[";
                for(int i = 0; i < ingred_values.size(); i++){
                    if(i != 0){
                        results_json << ",";
                    }
                    results_json << "{\"ingred\" : \"" << ingred_values[i] << "\",";
                    results_json << "\"store\" : \"" << store_values[i] << "\"}";
                }
                results_json<<"]";
            }

            results_json<<"}}";

            connection->Write(results_json.str());

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
