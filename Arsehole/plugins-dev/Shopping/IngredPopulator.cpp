#include "IngredPopulator.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/GoogleSearch/GoogleSearch.h"
#include "../../ArseholeCoreModules/CoreModules/TaskList/TaskList.h"
#include "../../ErrorLogger/Errors/ErrorLogger.h"

IngredPopulator::IngredPopulator(){

    m_shopping_dir = "/home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/plugins-dev/Shopping/";

}

void IngredPopulator::Initialise(
        std::shared_ptr<IHTTPUrlRouter> router,
        std::shared_ptr<TaskList> taskList,
        CommsNS::IComms* comms
    ){


    router->MapURLRequest(
        "/plugins/ShoppingList/SearchRecipies",
        [&, comms](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto search_term = connection->RequestParams()["m"];
            
            Comms::GoogleSearch search;
            //auto results = search.Search("BBQ Ribs", comms);

            // fake resuts 
            std::vector<Comms::GoogleSearch::Result> results;

            Comms::GoogleSearch::Result fake_result;
            fake_result.title = "Best Barbecue Ribs Recipe | How to Cook Ribs on the Grill Recipe ...";
            fake_result.url = "https://www.foodnetwork.com/recipes/katie-lee/best-barbecue-ribs-ever-3364398";
            fake_result.thumb_url = "https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcQ0CKR4Xj3jCIPUD8YTt33yYLw7SdhhgXBhun3sWZSQFDGo708yHRuGqyTB";
            fake_result.thumb_size = {259,149};

            results.push_back(fake_result);

            fake_result.title = "Sticky Oven Barbecue Ribs - Cafe Delites";
            fake_result.url = "https://cafedelites.com/oven-barbecue-ribs/";
            fake_result.thumb_url = "https://encrypted-tbn3.gstatic.com/images?q=tbn:ANd9GcSvoLb_u3Wq6ynwlG0N27-dujLgHgmRgs7jgqgQtldbrbNzwhd8kjLrioQ";
            fake_result.thumb_size = {182,275};

            results.push_back(fake_result);

            fake_result.title = "Lecture - Wikipedia3";
            fake_result.url = "https://en.wikipedia.org/wiki/Lecture";
            fake_result.thumb_url = "https://encrypted-tbn3.gstatic.com/images?q=tbn:ANd9GcRYNcgeCThseKJjdNKts1_p1AydhOuVRAZ_GszY_SOzmU-A_fb70gRMR5Y";
            fake_result.thumb_size = {275,183};

            results.push_back(fake_result);


            std::stringstream ss;
            ss << "[";
            int i = 0;
            for(auto& result : results){
                ss << result.ToJson();
                i++;
                if(i < results.size()){
                    ss << ",";
                }
            }
            ss << "]";
        
            connection->Write(ss.str());
    });


    router->MapURLRequest(
        "/plugins/ShoppingList/GetIngredients",
        [&, comms](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto url = connection->RequestParams()["m"];


            std::string cmd = m_shopping_dir + "extractIngreds " + url;
            bool exit_code = false;
            std::string output = taskList->RunSystemCommand(cmd, exit_code);

            if(!exit_code){
                ErrorLogger::logError("Got bad exit code from extracting ingreds");
            }

            connection->Write(output);

    });

}