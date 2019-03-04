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
            connection->Write(CheckForUpdate() ? "1" : "0");
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
){
    std::system("cd /home/craig/Programming/JARVIS/HTML-Media-Center && \
    git pull origin master > gitPullOut.txt");

    std::ifstream pull_output("/home/craig/Programming/JARVIS/HTML-Media-Center/gitPullOut.txt");
    std::string pull_out_str((std::istreambuf_iterator<char>(pull_output)),
                 std::istreambuf_iterator<char>());

    return pull_out_str.find("Already up-to-date") == std::string::npos;
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
