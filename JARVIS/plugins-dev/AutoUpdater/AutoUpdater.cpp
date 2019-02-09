#include "AutoUpdater.h"

#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"

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

}

AutoUpdater::~AutoUpdater(){

}

bool AutoUpdater::CheckForUpdate(
){
    std::system("cd /home/craig/Programming/JARVIS/HTML-Media-Center && \
    git pull origin master > gitPullOut.txt");

    std::ifstream pull_output("gitPullOut.txt");
    std::string pull_out_str((std::istreambuf_iterator<char>(pull_output)),
                 std::istreambuf_iterator<char>());

    return pull_out_str.find("Already up-to-date") == std::string::npos;
}

bool AutoUpdater::BuildUpdate(
){
    std::string updateCMD = "\\ "
     "cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/JARVISCoreModules/ \\ "
     "&& ./build_release \\ "
     "&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/JARVIS \\ "
     "&& cmake -DCMAKE_C_COMPILER=clang-6.0 -DCMAKE_CXX_COMPILER=clang-6.0 -DOPENSSL_ROOT_DIR=/openssl-1.0.2l/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=. CMakeLists.txt \\ "
     "&& make install \\ "
     "&& cp ./bin/JARVIS ../bin \\ "
     "&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/plugins-dev/Shopping \\ "
     "&& cmake -DCMAKE_C_COMPILER=clang-6.0 -DCMAKE_CXX_COMPILER=clang-6.0 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/home/JARVIS CMakeLists.txt \\ "
     "&& make install\\ "
     "&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/plugins-dev/AutoUpdater \\ "
     "&& cmake -DCMAKE_C_COMPILER=clang-6.0 -DCMAKE_CXX_COMPILER=clang-6.0 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/home/JARVIS CMakeLists.txt \\ "
     "&& make install";

    auto cmd = std::system(updateCMD.c_str());
    auto exit_code = WEXITSTATUS(cmd);

    return exit_code == 0;
}


void AutoUpdater::handleRequest(
    std::string requestURL
) {
}

const std::string AutoUpdater::pluginName(){
    return "Auto Updater";
}
