#include "FrameWork.h"

#include <stdio.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include <sstream>
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.h"
#include "../../JARVISCoreModules/CoreModules/Comms/HTTPServer/HTTPServer.h"
#include <list>

#ifdef _WINDOWS
#include <Windows.h>
#endif

JARVISFramework::JARVISFramework()
{
	ErrorLogger::logInfo("JARVIS initalising...");
	this->shuttingDown = false;

	this->cModules.getComms()->messagesubject()->onListPluginsMessageReceved.connect(this, &JARVISFramework::loadedPlugins);
	this->cModules.getComms()->messagesubject()->onDiagnosticMessageReceved.connect(this, &JARVISFramework::processDiagnosticMessage);


	EventManager::commandAndControlMessageReceved.attach(this,&JARVISFramework::commandAndControlMessageReceved);

	this->pluginPageResponder.reset(new PluginPageResponder(this->pluginLoader, this->cModules.getComms()));
	this->mediaStreamResponder.reset(new MediaStreamResponder(&this->cModules));
}

JARVISFramework::~JARVISFramework()
{
	delete this->pluginLoader;
}

void JARVISFramework::process()
{
	this->cModules.getComms()->startComms("/home/boss_man/Projects/HTML-Media-Center/JARVIS/JARVIS/Framework/Static_content/");
	boost::thread listenForConnectionThread(boost::bind(&JARVISFramework::processCommandLoop, this));

	this->cModules.getComms()->Server()->MapURLRequest(
		"/loadedPlugins", 
		[&](
			http::server<HTTPServer>::request,
            http::server<HTTPServer>::connection_ptr connection
		){
			std::vector<Plugin*> loadedPlugins;
			this->pluginLoader->listLoadedPlugins(&loadedPlugins);

			for(auto plugin : loadedPlugins){
				connection->write(plugin->pluginName());
			}
			
		}
	);

	#ifdef _WINDOWS
	this->pluginLoader = new Loader("C:\\wamp64\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\plugins");
#else
	this->pluginLoader = new Loader("/home/JARVIS");
#endif

	ErrorLogger::logInfo("Loading Modules");
	this->loadStartupPlugins();
	ErrorLogger::logInfo("Modules Loaded");

	this->cModules.getTaskList().StartTasks();
	while(!this->shuttingDown)
	{
#ifdef _WINDOWS
		Sleep(1000); // sleep for a second
#else
		sleep(1);
#endif
	}

	this->cModules.getComms()->stopComms();
	ErrorLogger::logInfo("Shutting down");
}

void JARVISFramework::loadStartupPlugins()
{
	namespace fs = boost::filesystem;
	fs::path pluginDirectory(this->pluginLoader->PluginDir());
	fs::directory_iterator end_iter;

	Plugin* mediaImages = NULL;

	if(!fs::exists(pluginDirectory))
	{
		ErrorLogger::logError("Plugin Directory dosnt exist!!");
		return;
	}

	for( fs::directory_iterator dir_iter(pluginDirectory) ; dir_iter != end_iter ; ++dir_iter)
	  {
	    if ( !fs::is_directory( *dir_iter ))
	    {
	    	fs::path path = dir_iter->path();
	    	std::string filenameStr = path.filename().string();
	    	pluginLoader->loadPlugin(filenameStr,&mediaImages, &this->cModules);

	    }
	  }
}


void JARVISFramework::processDiagnosticMessage(TranslatedMessages::RequestDisagnosticsMessage* msg,
		coremodules::comms::protocals::IProtocal* protocal)
{
	std::stringstream statusMessage;

	bool dbConnection = cModules.getDatabaseConnection()->isConnected();
	statusMessage << "Database Connection{Connection Status:";
	if(dbConnection)
		statusMessage << "1";
	else
		statusMessage << "0";

	statusMessage << "},Audio Devices{";
	std::list<AudioDevice> audioDevices;
	cModules.getMediaStreamer().Get_Audio_Devices(audioDevices);
	std::list<AudioDevice>::iterator lastDevice = audioDevices.end();
	--lastDevice;
	for(std::list<AudioDevice>::iterator device = audioDevices.begin();
			device != audioDevices.end(); device++)
	{
		statusMessage << device->Get_Name() << ":1";
		if(device != lastDevice)
			statusMessage << ".";
	}
	statusMessage << "}";
	protocal->sendMessage(new TranslatedMessages::ReplyMessage(statusMessage.str()));

}


void JARVISFramework::loadedPlugins(ListPluginsMessage*, coremodules::comms::protocals::IProtocal* protocal)
{
	using namespace std;
	std::stringstream reply;
	std::vector<Plugin*> loadedPlugins;
	this->pluginLoader->listLoadedPlugins(&loadedPlugins);

	std::list<std::string> misc, music, movie, tv, content, prog;
	// TODO tidy this crap
	for(vector<Plugin*>::iterator it2 = loadedPlugins.begin(); it2 != loadedPlugins.end(); it2++)
	{
		switch((*it2)->pluginGroup())
		{
			case(Plugin::CONTENT_GEN):
				content.push_back((*it2)->pluginName());
			break;
			case(Plugin::MISC):
				misc.push_back((*it2)->pluginName());
			break;
			case(Plugin::MOVIE):
				movie.push_back((*it2)->pluginName());
			break;
			case(Plugin::MUSIC):
				music.push_back((*it2)->pluginName());
			break;
			case(Plugin::TV):
				tv.push_back((*it2)->pluginName());
			break;
			case(Plugin::PROG):
				prog.push_back((*it2)->pluginName());
			break;
		}
	}

	if(content.size() > 0)
	{
		reply << "%Content Creation";
		for(std::list<std::string>::iterator it = content.begin(); it != content.end(); it++)
		{
			reply << "," << *it;
		}
	}

	if(music.size() > 0)
	{
	reply << "%Music";
	for(std::list<std::string>::iterator it = music.begin(); it != music.end(); it++)
	{
		reply << "," << *it;
	}
	}

	if(movie.size() > 0)
	{
		reply << "%Movie";
	for(std::list<std::string>::iterator it = movie.begin(); it != movie.end(); it++)
	{
		reply << "," << *it;
	}
	}

	if(tv.size() > 0)
	{
		reply << "%Tv";
	for(std::list<std::string>::iterator it = tv.begin(); it != tv.end(); it++)
	{
		reply << "," << *it;
	}
	}

	if(prog.size() > 0)
	{
		reply << "%Programming";
	for(std::list<std::string>::iterator it = prog.begin(); it != prog.end(); it++)
	{
		reply << "," << *it;
	}
	}

	if(misc.size() > 0)
	{
	reply << "%miscellaneous";
	for(std::list<std::string>::iterator it = misc.begin(); it != misc.end(); it++)
	{
		reply << "," << *it;
	}
	}

	protocal->sendMessage(new TranslatedMessages::ReplyMessage(reply.str()));
}

void JARVISFramework::processCommandLoop()
{
	std::string command;
	const unsigned buffer_size = 100;
	char buffer[buffer_size];

	while(!this->shuttingDown)
	{
		std::cin.getline(buffer, buffer_size);
		command = buffer;
		if(command == "shutdown")
		{
				this->shuttingDown = true;
				return;
		}
		else if(command == "media resend_handshake")
		{
			this->cModules.getMediaStreamer().Resend_Agent_Handshake_Message();
		}
		else
		{
			ErrorLogger::logError("Unrecognised Command:" + command);
		}
	}
}

bool JARVISFramework::commandAndControlMessageReceved(int type)
{
	//TODO change type to an enum when i get the time

	switch(type)
	{
		case 1: // shutdown command
			this->shuttingDown = true;
		break;
		case 2: // havent deided yet
		break;

		default: // unknown command and control message
			return false;
		break;

	}

	return true;

}


