#include "Shopping.h"
#include "../../ArseholeCoreModules/CoreModules/Database/Querys/NoBullshitQuery.h"
#include "../../ArseholeCoreModules/CoreModules/Database/Results/ResultTypes.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string/join.hpp>

extern const char meal_name_col[] = "meal_name";
extern const char ingred_name_col[] = "ingredient_name";
extern const char ingred_store_col[] = "store";
extern const char selected_meal_name_col[] = "selected_meal";
extern const char selected_ingred_name_col[] = "selected_ingred";
extern const char ingred_id_col[] = "id";


ShoppingPlugin::ShoppingPlugin(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto router = comms->Router();

    router->RegisterWidgit("plugins/Shopping_content");

    auto db = cm->getDatabaseConnection();



    router->MapURLRequest(
        "/plugins/ShoppingList",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            DatabaseTables::NoBullshitQuery query("\
                SELECT Meals.meal_name, Meals.selected_meal, \
                    Ingredients.id, Ingredients.ingredient_name, Ingredients.store, Ingredients.selected_ingred\
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
            this->processSelectedMessages(connection, true);  
    });

    router->MapURLRequest(
        "/plugins/ShoppingList/PendingSelected",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            // This handler is invoked when the serivce worker 
            // reconnects with pending messages

            // right now just process the messages in an additive way 
            // ( you cant delete anything when your not 'live')
            processSelectedMessages(connection, false);

    });

    router->MapURLRequest(
        "/plugins/ShoppingList/UpdateExtras",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            this->processExtras(connection);  
    });

    router->MapURLRequest(
        "/plugins/ShoppingList/GetExtras",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            this->getExtras(connection);  
    });

    router->MapURLRequest(
        "/plugins/ShoppingList/AddMeal",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            AddMeal(connection);
    });


}

ShoppingPlugin::~ShoppingPlugin(){

}

void ShoppingPlugin::setSelectedMeals(
    const std::vector<std::string>& selected_meals,
    bool allow_unset
){
    if(selected_meals.size() == 0 && allow_unset ){

        DatabaseTables::NoBullshitQuery selected_query(
            "UPDATE Meals SET selected_meal = 0");       

        ResultWrapper result_wrapper;
        this->coreMod->getDatabaseConnection()->runQuery(
            &selected_query, 
            result_wrapper);

    } else if(selected_meals.size() != 0) {

        std::string meals = boost::algorithm::join(selected_meals, ",");
        DatabaseTables::NoBullshitQuery selected_query(
            "UPDATE Meals SET selected_meal = 1 WHERE Meals.meal_name IN ("+meals+")");       

        ResultWrapper result_wrapper;
        this->coreMod->getDatabaseConnection()->runQuery(
            &selected_query, 
            result_wrapper);

        if(allow_unset){
            DatabaseTables::NoBullshitQuery unselected_query(
                "UPDATE Meals SET selected_meal = 0 WHERE Meals.meal_name NOT IN ("+meals+")");       
                
            this->coreMod->getDatabaseConnection()->runQuery(
                &unselected_query, 
                result_wrapper
            );
        }
    }
}

void ShoppingPlugin::setSelectedIngreds(
    const std::vector<std::string>& selected_ingredient_ids,
    bool allow_unset
){
    if(selected_ingredient_ids.size() == 0 && allow_unset){

        DatabaseTables::NoBullshitQuery query(
            "UPDATE Ingredients SET selected_ingred = 0");      

        ResultWrapper result_wrapper;
        this->coreMod->getDatabaseConnection()->runQuery(
            &query, 
            result_wrapper);

    } else if(selected_ingredient_ids.size() != 0 ){
        std::string ingredients = boost::algorithm::join(selected_ingredient_ids, ",");

        DatabaseTables::NoBullshitQuery query(
            "UPDATE Ingredients SET selected_ingred = 1 WHERE Ingredients.id IN ("+ingredients+")");      

        ResultWrapper result_wrapper;
        this->coreMod->getDatabaseConnection()->runQuery(
            &query, 
            result_wrapper);

        if(allow_unset){
            DatabaseTables::NoBullshitQuery unselected_query(
                "UPDATE Ingredients SET selected_ingred = 0 WHERE Ingredients.id NOT IN ("+ingredients+")");

            this->coreMod->getDatabaseConnection()->runQuery(
                &unselected_query, 
                result_wrapper
            );
        }
    }

    
               
}

void ShoppingPlugin::processSelectedMessages(
    std::shared_ptr<IHTTPUrlRouter::IConnection> connection,
    bool allow_unselect
) {
    auto selected = connection->RequestBody();

    // parse JSON with property tree
    namespace pt = boost::property_tree;

    // Create a root
    pt::ptree root;

    std::stringstream selected_json(selected);
    // Load the json file in this ptree
    pt::read_json(selected_json, root);

    std::vector<std::string> selected_meals;
    std::vector<std::string> selected_ingredient_ids;

    for(auto iter = root.begin(); iter != root.end(); iter++)
    {
        auto selected = iter->second.get<std::string>("selected");
        
        if(selected.compare("1") ==0 ){
            selected_meals.push_back("'"+iter->first+"'");
        }

        auto ingredients = iter->second.get_child("ingreds");
        for(auto iter2 = ingredients.begin(); iter2 != ingredients.end(); iter2++){
            auto selected = iter2->second.get<std::string>("selected");
            if(selected.compare("1") == 0){
                selected_ingredient_ids.push_back("'"+iter2->second.get<std::string>("id")+"'");
            }
        }
        
    }
    // put them in the db
    setSelectedIngreds(selected_ingredient_ids, allow_unselect);
    setSelectedMeals(selected_meals, allow_unselect);
}

void ShoppingPlugin::processExtras(
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection
) {
    auto extras_json = connection->RequestBody();

    // parse JSON with property tree
    namespace pt = boost::property_tree;

    // Create a root
    pt::ptree root;

    std::stringstream selected_json(extras_json);
    // Load the json file in this ptree
    pt::read_json(selected_json, root);
   
    auto extras_node = root.get_child("extras");

    std::vector<std::string> extras;
    for(auto iter = extras_node.begin(); iter != extras_node.end(); iter++){
        extras.push_back("(null,'"+
            iter->second.get<std::string>("ingred") + "','" +
            iter->second.get<std::string>("store") + "')");
    }

    std::string all_extras = boost::algorithm::join(extras, ",");
    DatabaseTables::NoBullshitQuery selected_query(
        "INSERT INTO Extras VALUES "+all_extras );       

    DatabaseTables::NoBullshitQuery delete_query(
        "DELETE FROM Extras");       

    ResultWrapper result_wrapper;
    this->coreMod->getDatabaseConnection()->runQuery(
        &delete_query, 
        result_wrapper);
        
    this->coreMod->getDatabaseConnection()->runQuery(
        &selected_query, 
        result_wrapper);
}

void ShoppingPlugin::getExtras(
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection
) {
    

    DatabaseTables::NoBullshitQuery selected_query(
        "SELECT * from Extras" );       

    ResultWrapper result_wrapper;
    this->coreMod->getDatabaseConnection()->runQuery(
        &selected_query, 
        result_wrapper);

    auto results = Results<
        ResultRow<
            Column<std::string, ingred_name_col>,
            Column<std::string, ingred_store_col>
        >>(result_wrapper);   


    std::stringstream results_json;
    results_json << "{\"extras\":[";

    bool first = true;
    for (auto& row : results){

        auto ingredient = std::get<0>(row->Row()).Value();
        auto store = std::get<1>(row->Row()).Value();

        if(!first){
            results_json << ",";    
        }
        first = false;
        results_json << "{";
        results_json << "\"store\":\""<<store<<"\",";
        results_json << "\"ingred\":\""<<ingredient<<"\"";
        results_json << "}";
    }

    results_json << "]}";

    connection->Write(results_json.str());

}

std::string ShoppingPlugin::resultsToString(
		ResultWrapper& result_wrapper
) {
    auto results = Results<
            ResultGroup<
                std::string,
                meal_name_col,
                ResultList<Column<std::string, selected_meal_name_col>>,
                ResultList<Column<std::string, ingred_name_col>>,
                ResultList<Column<std::string, ingred_store_col>>,
                ResultList<Column<bool, selected_ingred_name_col>>,
                ResultList<Column<int, ingred_id_col>>
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

        results_json << "\"" << meal->Value() << "\" : {";


        // this is just like this because its currently not possible 
        // to have the results wrapper group on >1 column
        auto selected_meal = std::get<0>(meal->Children());
        auto selected_meals_values = selected_meal.Values();

        results_json << "\"selected\" : " << selected_meals_values[0].Value() << ",";


        auto ingredients = std::get<1>(meal->Children());
        auto ingred_store = std::get<2>(meal->Children());
        auto selected_ingreds = std::get<3>(meal->Children());
        auto ingredients_id = std::get<4>(meal->Children());


        auto ingred_values = ingredients.Values();
        auto store_values = ingred_store.Values();
        auto selected_values = selected_ingreds.Values();
        auto ingred_ids = ingredients_id.Values();
        

        if(store_values.size() != 
            ingred_values.size() ||
            store_values.size() !=
            selected_values.size() ||
            selected_meals_values.size() !=
            store_values.size()){

                ErrorLogger::logWarn("sad times, store and ingredient results not the same size");
                return "";
        }

        results_json << "\"ingreds\": [";
        for(int i = 0; i < ingred_values.size(); i++){
            if(i != 0){
                results_json << ",";
            }
            results_json << "{"
            << "\"ingred\": \"" << ingred_values[i].Value() << "\","
            << "\"store\" : \"" << store_values[i].Value() << "\","
            << "\"id\" : \"" << ingred_ids[i].Value() << "\","
            << "\"selected\" : \"" << selected_values[i].Value() << "\""
            << "}";
        }
        results_json<<"]}";
    }

    results_json<<"}";

    return results_json.str();

}

void ShoppingPlugin::AddMeal(
    std::shared_ptr<IHTTPUrlRouter::IConnection> connection
){
    auto meal_data = connection->RequestBody();

    // parse JSON with property tree
    namespace pt = boost::property_tree;

    // Create a root
    pt::ptree root;

    std::stringstream meal_data_json(meal_data);
    // Load the json file in this ptree
    pt::read_json(meal_data_json, root);

    std::string meal_name = root.get<std::string>("name");

    auto aldi = root.get_child("aldi");
    std::vector<std::string> aldi_ingreds;
    for(auto iter = aldi.begin(); iter != aldi.end(); iter++) {
        aldi_ingreds.push_back(iter->second.get_value<std::string>());
    }

    auto sains = root.get_child("sains");
    std::vector<std::string> sains_ingreds;
    for(auto iter = sains.begin(); iter != sains.end(); iter++) {
        sains_ingreds.push_back(iter->second.get_value<std::string>());
    }

    ResultWrapper result_wrapper;
    auto abort_if_Failed = [&](bool val){
        if(!val){
            DatabaseTables::NoBullshitQuery rollback_query("ROLLBACK");
            this->coreMod->getDatabaseConnection()->runQuery(
                &rollback_query, 
                result_wrapper);

            connection->Write("Query Failure");
        }
        return val;
    };

    DatabaseTables::NoBullshitQuery start_transaction_query("START TRANSACTION");
    DatabaseTables::NoBullshitQuery insert_meal_query("INSERT INTO Meals VALUES(null, \""+meal_name+"\",0)");
    this->coreMod->getDatabaseConnection()->runQuery(
        &start_transaction_query, 
        result_wrapper);

    bool suceeded = abort_if_Failed(this->coreMod->getDatabaseConnection()->runQuery(
        &insert_meal_query, 
        result_wrapper));
    if(!suceeded) return;

    for(auto ingred : aldi_ingreds){
        DatabaseTables::NoBullshitQuery insert_ingred_querys(
            "INSERT INTO Ingredients VALUES(null, \""+ingred+"\", \"Aldi\", \
            (SELECT id FROM Meals WHERE meal_name = '"+meal_name+"') ,0);"
        );
        suceeded = abort_if_Failed(this->coreMod->getDatabaseConnection()->runQuery(
            &insert_ingred_querys, 
            result_wrapper));
        if(!suceeded) return;

    }

    for(auto ingred : sains_ingreds){
        DatabaseTables::NoBullshitQuery insert_ingred_querys(
            "INSERT INTO Ingredients VALUES(null, \""+ingred+"\", \"Sainsbury\", \
            (SELECT id FROM Meals WHERE meal_name = '"+meal_name+"') ,0);"
        );
        suceeded = abort_if_Failed(this->coreMod->getDatabaseConnection()->runQuery(
            &insert_ingred_querys, 
            result_wrapper));
        if(!suceeded) return;

    }
    
    // we got this far so commit the transaction
    DatabaseTables::NoBullshitQuery commit_query("COMMIT");
    this->coreMod->getDatabaseConnection()->runQuery(
        &commit_query, 
        result_wrapper);
    
    
    connection->Write("OK");
}

void ShoppingPlugin::handleRequest(
    std::string requestURL
) {


}

const std::string ShoppingPlugin::pluginName(){
    return "Shopping";
}
