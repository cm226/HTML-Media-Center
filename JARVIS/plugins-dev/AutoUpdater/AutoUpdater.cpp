#include "AutoUpdater.h"

#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../JARVISCoreModules/CoreModules/config.h"

#include <stdlib.h> 
#include <fstream>
#include <cstdlib>


AutoUpdater::AutoUpdater(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto router = comms->Router();

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
                        Restart();
                    } else {
                        ErrorLogger::logError("Failed to build update");
                    }
                    
                });
            }

            connection->Write("building");
        }
    ); 

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
    output = this->coreMod->getTaskList().RunSystemCommand(
        "(cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/ && git pull origin master)",
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
    if(LIVE){
        updateCMD = "/home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/BuildAll.sh Release";
    } else {
        updateCMD = "/home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/BuildAll.sh Debug";
    }
    

    bool normal_exit = false;
    std::string output = this->coreMod->getTaskList().RunSystemCommand(updateCMD, normal_exit);

    if(!normal_exit){
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
