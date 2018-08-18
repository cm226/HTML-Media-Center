
#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/HTTPServer.h"
#include "MusicGlob.h"

MusicGlobPlugin::MusicGlobPlugin(CoreModules* cm)
    :Plugin(cm){

        auto comms = cm->getComms();
        auto server = comms->Server();

        server->MapURLRequest(
            "/plugins/Music%20Glob",
            [&](
                http::server<HTTPServer>::request,
                http::server<HTTPServer>::connection_ptr connection
            ){
                connection->write("<html><h1>Globs</h1></html>");
            }
        );

}

MusicGlobPlugin::~MusicGlobPlugin(){

}

void MusicGlobPlugin::handleRequest(std::string requestURL){


}

const std::string MusicGlobPlugin::pluginName(){
    return "Music Glob";
}