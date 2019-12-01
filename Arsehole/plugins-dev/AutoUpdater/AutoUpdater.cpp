#include "AutoUpdater.h"

#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../ArseholeCoreModules/CoreModules/config.h"

#include <stdlib.h> 
#include <fstream>
#include <cstdlib>


AutoUpdater::AutoUpdater(
    CoreModules* cm
):
    Plugin(cm),
    m_stage("")
{
    auto comms = cm->getComms();
    auto router = comms->Router();
    
    router->RegisterWidgit("plugins/AutoUpdater_content");

    router->MapURLRequest(
        "/plugins/AutoUpdater/check_update",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            std::string output;
            bool have_update = CheckForUpdate(output);
            if(have_update){
                connection->Write("1," + output);
            } else {
                connection->Write("0," + output);
            }
        }
    );    

    router->MapURLRequest(
        "/plugins/AutoUpdater/update",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            std::lock_guard<std::mutex> lock(m_build_mutex);

            if(m_build_thread == nullptr ){
                m_build_thread = std::make_unique<std::thread>([&](){
                    if(BuildUpdate()){
                        {
                            std::lock_guard<std::mutex> lk(m_build_stage_changed);
                            m_stage = "Restart";
                        }
                        m_build_stage_cv.notify_one();
                        // allow time to let client know about the new stage
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        Restart();
                    } else {
                        ErrorLogger::logError("Failed to build update");
                    }
                    
                });
            }
        }
    );

    router->MapURLRequest(
        "/plugins/AutoUpdater/getStage",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            auto params = connection->RequestParams();
            auto force_send = params.find("force_send") != params.end();

            if (m_stage != m_sentStage || force_send) {
                connection->Write(m_stage);
                m_sentStage = m_stage;
                return;
            }

            std::unique_lock<std::mutex> lk(m_build_stage_changed);
            m_build_stage_cv.wait(lk, [&]{return m_stage != m_sentStage;});
            
            connection->Write(m_stage);
            m_sentStage = m_stage;
    });

}

AutoUpdater::~AutoUpdater()
{
    if(m_build_thread != nullptr){
        m_build_thread->join();
    }
}

bool AutoUpdater::CheckForUpdate(
    std::string& output
){
    bool normal_exit = false;
    {
        std::lock_guard<std::mutex> lk(m_build_stage_changed);
        m_stage = "Pull";
    }
    m_build_stage_cv.notify_one();

    output = this->coreMod->getTaskList().RunSystemCommand(
        "(cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/ && git pull origin master)",
        normal_exit);
    

    bool haveUpdates = output.find("Already up to date") == std::string::npos;

    if(!normal_exit){
        ErrorLogger::logError("Got error from pull: " + output);
        return false;
    }

    return haveUpdates;
}

bool AutoUpdater::BuildUpdate(
){
    std::string updateCMD;

    {
        std::lock_guard<std::mutex> lk(m_build_stage_changed);
        m_stage = "Build";
    }
    m_build_stage_cv.notify_one();

    if(Config::GetInstance()->Live()){
        updateCMD = "/home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/BuildAll.sh Release";
    } else {
        updateCMD = "/home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/BuildAll.sh Debug";
    }
    

    bool normal_exit = false;
    std::string output = this->coreMod->getTaskList().RunSystemCommand(updateCMD, normal_exit);

    if(!normal_exit){

        {
            std::lock_guard<std::mutex> lk(m_build_stage_changed);
            m_stage = "Build_failed";
        }
        m_build_stage_cv.notify_one();

        ErrorLogger::logError("Got abnormal exit from update command, the output was : " + output);
    }

    return normal_exit;
}

void AutoUpdater::Restart(){
    coreMod->getComms()->sig_shutdown();
}


void AutoUpdater::handleRequest(
    std::string requestURL
) {
}

const std::string AutoUpdater::pluginName(){
    return "AutoUpdater";
}
