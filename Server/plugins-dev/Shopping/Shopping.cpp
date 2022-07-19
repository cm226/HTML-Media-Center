#include "Shopping.h"
#include "../../ServerCoreModules/CoreModules/Database/Querys/NoBullshitQuery.h"
#include "../../ServerCoreModules/CoreModules/Database/Results/ResultTypes.h"
#include "../../ServerCoreModules/CoreModules/Database/Querys/ScopedTransaction.h"

#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string/join.hpp>

extern const char meal_name_col[] = "meal_name";
extern const char ingred_name_col[] = "ingredient_name";
extern const char ingred_store_col[] = "store";
extern const char selected_meal_name_col[] = "selected_meal";
extern const char selected_ingred_name_col[] = "selected_ingred";
extern const char ingred_id_col[] = "id";

// parse JSON with property tree
namespace pt = boost::property_tree;



ShoppingPlugin::ShoppingPlugin(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto router = comms->Router();

    router->RegisterPluginPage("Listu-chan", "plugins/Shopping_content");

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
        auto selected = iter->second.get<bool>("selected");
        
        if(selected){
            selected_meals.push_back("'"+iter->first+"'");
        }

        auto ingredients = iter->second.get_child("ingreds");
        for(auto iter2 = ingredients.begin(); iter2 != ingredients.end(); iter2++){
            auto selected = iter2->second.get<bool>("selected");
            if(selected){
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

    // Create a root
    pt::ptree root;

    std::stringstream selected_json(extras_json);
    // Load the json file in this ptree
    pt::read_json(selected_json, root);
   
    auto extras_node = root.get_child("extras");

    std::vector<std::string> extras;
    for(auto iter = extras_node.begin(); iter != extras_node.end(); iter++){

        std::string ingred = 
            this->coreMod->getDatabaseConnection()->sanitizeString(
                iter->second.get<std::string>("ingred"));

        std::string store =
            this->coreMod->getDatabaseConnection()->sanitizeString(
                iter->second.get<std::string>("store"));
 
        extras.push_back("(null,'"+ ingred + "','" + store + "')");
    }

    DatabaseTables::NoBullshitQuery delete_query(
        "DELETE FROM Extras");       

    ResultWrapper result_wrapper;
    this->coreMod->getDatabaseConnection()->runQuery(
        &delete_query, 
        result_wrapper);

    if(extras.size() == 0){
        return;
    }

    std::string all_extras = boost::algorithm::join(extras, ",");
    DatabaseTables::NoBullshitQuery selected_query(
        "INSERT INTO Extras VALUES "+all_extras );       
        
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
            Column<std::string, ingred_id_col>,
            Column<std::string, ingred_name_col>,
            Column<std::string, ingred_store_col>
        >>(result_wrapper);   


    std::stringstream results_json;
    results_json << "{\"extras\":[";

    bool first = true;
    for (auto& row : results) {

        auto id = std::get<0>(row->Row()).Value();
        auto ingredient = std::get<1>(row->Row()).Value();
        auto store = std::get<2>(row->Row()).Value();

        if(!first){
            results_json << ",";    
        }
        first = false;
        results_json << "{";
        results_json << "\"id\":"<<id<<",";
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
            << "\"selected\" : " << selected_values[i].Value() << ""
            << "}";
        }
        results_json<<"]}";
    }

    results_json<<"}";

    return results_json.str();

}

void ShoppingPlugin::GetIngredsFromJSON(
    std::shared_ptr<std::vector<std::string>> sains_ingreds,
    std::shared_ptr<std::vector<std::string>> aldi_ingreds,
    pt::ptree root
){

    auto aldi = root.get_child("aldi");
    for(auto iter = aldi.begin(); iter != aldi.end(); iter++) {
        aldi_ingreds->push_back(iter->second.get_value<std::string>());
    }

    auto sains = root.get_child("sains");
    for(auto iter = sains.begin(); iter != sains.end(); iter++) {
        sains_ingreds->push_back(iter->second.get_value<std::string>());
    }
}


bool ShoppingPlugin::InsertAllIngredsFromJson(
    std::shared_ptr<std::vector<std::string>> sains_ingreds,
    std::shared_ptr<std::vector<std::string>> aldi_ingreds,
    std::string meal_name
) {
    ResultWrapper result_wrapper;

    for(auto ingred : *aldi_ingreds){
        DatabaseTables::NoBullshitQuery insert_ingred_querys(
            "INSERT INTO Ingredients VALUES(null, \""+ingred+"\", \"Aldi\", \
            (SELECT id FROM Meals WHERE meal_name = '"+meal_name+"') ,0);"
        );
        if(!this->coreMod->getDatabaseConnection()->runQuery(
            &insert_ingred_querys, 
            result_wrapper))
        return false;

    }

    for(auto ingred : *sains_ingreds){
        DatabaseTables::NoBullshitQuery insert_ingred_querys(
            "INSERT INTO Ingredients VALUES(null, \""+ingred+"\", \"Sainsbury\", \
            (SELECT id FROM Meals WHERE meal_name = '"+meal_name+"') ,0);"
        );
        if(!this->coreMod->getDatabaseConnection()->runQuery(
            &insert_ingred_querys, 
            result_wrapper))
        return false;

    }

    return true;
    
}

void ShoppingPlugin::EditMeal(
    std::shared_ptr<IHTTPUrlRouter::IConnection> connection
) {
    auto meal_data = connection->RequestBody();

    // Create a root
    pt::ptree root;

    std::stringstream meal_data_json(meal_data);
    // Load the json file in this ptree
    pt::read_json(meal_data_json, root);

    std::string meal_name = root.get<std::string>("name");

    DatabaseTables::ScopedTransaction transaction(
        this->coreMod->getDatabaseConnection()
    );

    ResultWrapper result_wrapper;
    auto abort_if_Failed = [&](bool val){
        if(!val){
            transaction.Abort();
            connection->Write("Query Failure");
        }
        return val;
    };

    DatabaseTables::NoBullshitQuery delete_old_ingreds_query(
    "DELETE FROM Ingredients WHERE meal_id = (SELECT id FROM Meals WHERE meal_name = '"+
        meal_name
    +"');");

    if(!abort_if_Failed(this->coreMod->getDatabaseConnection()->runQuery(
            &delete_old_ingreds_query, 
            result_wrapper))
    ) return;
    

    auto aldi_ingreds = std::make_shared<std::vector<std::string>>();
    auto sains_ingreds = std::make_shared<std::vector<std::string>>();
    GetIngredsFromJSON(
        sains_ingreds, 
        aldi_ingreds,
        root
    );

    bool suceeded = abort_if_Failed(InsertAllIngredsFromJson(
    sains_ingreds,
    aldi_ingreds, 
    meal_name));

    if(!suceeded) return;
    
    
    connection->Write("OK");


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

    auto aldi_ingreds = std::make_shared<std::vector<std::string>>();
    auto sains_ingreds = std::make_shared<std::vector<std::string>>();
    GetIngredsFromJSON(
        sains_ingreds, 
        aldi_ingreds,
        root
    );

    DatabaseTables::ScopedTransaction transaction(
        this->coreMod->getDatabaseConnection()
    );
    ResultWrapper result_wrapper;
    auto abort_if_Failed = [&](bool val){
        if(!val){
            transaction.Abort();
            connection->Write("Query Failure");
        }
        return val;
    };

    // Check if that meal already exists and 
    DatabaseTables::NoBullshitQuery meal_exists_query("SELECT 1 FROM Meals WHERE meal_name = \""+meal_name+"\"");
    bool suceeded = abort_if_Failed(this->coreMod->getDatabaseConnection()->runQuery(
        &meal_exists_query, 
        result_wrapper));
    if(!suceeded) {
        connection->Write("FAIL");
        return;
    }

    if(result_wrapper.next()){
        // meal already exists, we we are editing, clear meal
        DatabaseTables::NoBullshitQuery delete_all_ingreds(
            "DELETE FROM Ingredients WHERE meal_id = (SELECT id FROM Meals WHERE meal_name = '"+meal_name+"')"
        );
        suceeded = abort_if_Failed(this->coreMod->getDatabaseConnection()->runQuery(
            &delete_all_ingreds, 
            result_wrapper));
        if(!suceeded) {
            connection->Write("FAIL");
            return;
        }
    } else {
        // meal dosnt exist so add it
        DatabaseTables::NoBullshitQuery insert_meal_query("INSERT INTO Meals VALUES(null, \""+meal_name+"\",0)");
        ResultWrapper insertResults;
        suceeded = abort_if_Failed(this->coreMod->getDatabaseConnection()->runQuery(
            &insert_meal_query, 
            insertResults));
        if(!suceeded) {
            connection->Write("FAIL");
            return;
        }
    }

    
    suceeded = abort_if_Failed(InsertAllIngredsFromJson(
        sains_ingreds,
        aldi_ingreds, 
        meal_name));

    if(!suceeded) {
        connection->Write("FAIL");
        return;
    }
    
    connection->Write("OK");
}

void ShoppingPlugin::handleRequest(
    std::string requestURL
) {


}

const std::string ShoppingPlugin::pluginName(){
    return "Shopping";
}
