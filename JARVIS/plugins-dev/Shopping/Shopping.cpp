#include "Shopping.h"
#include "../../JARVISCoreModules/CoreModules/Database/Querys/NoBullshitQuery.h"
#include "../../JARVISCoreModules/CoreModules/Database/Results/ResultTypes.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

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

            connection->Write(resultsToString(result_wrapper));

        }
    );

    router->MapURLRequest(
        "/plugins/ShoppingList/UpdateSelected",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            ResultWrapper result_wrapper;
            DatabaseTables::NoBullshitQuery query("DELETE FROM SelectedIngredients");
            this->coreMod->getDatabaseConnection()->runQuery(
                &query, 
                result_wrapper);

            this->processSelectedMessages(connection);
            
    });

    router->MapURLRequest(
        "/plugins/ShoppingList/PendingSelected",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            // This handler is invoked when the serice worker 
            // reconnects with pending messages

            // right now just process the messages in an additive way 
            // ( you cant delete anything when you 'live')
            processSelectedMessages(connection);

        });



    router->MapURLRequest(
        "/plugins/ShoppingList/GetSelected",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            DatabaseTables::NoBullshitQuery query("\
                SELECT Meals.meal_name, Ingredients.ingredient_name, Ingredients.store\
                FROM Meals, SelectedIngredients, Ingredients\
                WHERE Meals.id=SelectedIngredients.meal_id AND SelectedIngredients.id = Ingredients.id\
                ORDER BY Meals.meal_name");
                
            ResultWrapper result_wrapper;
            this->coreMod->getDatabaseConnection()->runQuery(
                &query, 
                result_wrapper);

            connection->Write(resultsToString(result_wrapper));

    });


}

ShoppingPlugin::~ShoppingPlugin(){

}

void ShoppingPlugin::processSelectedMessages(
    std::shared_ptr<IHTTPUrlRouter::IConnection> connection
) {
    auto selected = connection->RequestBody();

    // parse JSON with property tree
    namespace pt = boost::property_tree;

    // Create a root
    pt::ptree root;

    std::stringstream selected_json(selected);
    // Load the json file in this ptree
    pt::read_json(selected_json, root);

    std::vector<std::pair<
        std::string,
        std::vector<std::pair<std::string, std::string>> 
    >> selected_meals;

    for(auto iter = root.begin(); iter != root.end(); iter++)
    {
        std::vector<std::pair<std::string, std::string>> ingreds;
        for(auto iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++){
            ingreds.push_back(
                {iter2->second.get<std::string>("store"),
                iter2->second.get<std::string>("ingred")});
        }
        selected_meals.push_back(
            {iter->first, ingreds});
    }


    ResultWrapper result_wrapper;
    for(auto meal : selected_meals){

            for(auto ingred : meal.second){
                DatabaseTables::NoBullshitQuery query("\
                    INSERT INTO SelectedIngredients(id, meal_id) VALUES(\
                        (SELECT id FROM Ingredients WHERE ingredient_name='"+ingred.second+"' AND store='"+ingred.first+"'),\
                        (SELECT id FROM Meals WHERE meal_name='"+meal.first+"')\
                    )");
                this->coreMod->getDatabaseConnection()->runQuery(
                    &query, 
                    result_wrapper);
            }
    }

}

std::string ShoppingPlugin::resultsToString(
		ResultWrapper& result_wrapper
) {
    auto results = Results<
            ResultGroup<
                std::string,
                meal_name_col,
                ResultList<std::string, ingred_name_col>,
                ResultList<std::string, ingred_store_col>
            >
        >(result_wrapper);            

    std::stringstream results_json;
    results_json << "{";

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
                return "";
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

    results_json<<"}";

    return results_json.str();

}

void ShoppingPlugin::handleRequest(
    std::string requestURL
) {


}

const std::string ShoppingPlugin::pluginName(){
    return "Shopping";
}
