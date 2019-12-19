#include "FrameWork.h"

#include <stdio.h>
#include <thread>
#include <boost/filesystem.hpp>
#include <sstream>
#include "../../ArseholeCoreModules/CoreModules/config.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/HTTPServer.h"
#include <list>
#include <chrono>
#include <future>

#include <sys/select.h>

#include <cctype>

#include "../../ArseholeCoreModules/CoreModules/TaskList/Schedual.h"

#ifdef _WINDOWS
#include <Windows.h>
#endif

ArseholeFramework::ArseholeFramework()
{
	Config::ReadConfig("config.ini");

	cModules = std::make_shared<CoreModules>();

	ErrorLogger::logInfo("Arsehole initalising...");
	this->shuttingDown = false;

	this->cModules->getComms()->messagesubject()->onDiagnosticMessageReceved.connect(this, &ArseholeFramework::processDiagnosticMessage);

	this->cModules->getComms()->sig_shutdown.connect([this](){
		std::unique_lock<std::mutex> lk(m_shutdown_mutext);
		this->shuttingDown = true;
		m_shutdown_cv.notify_one();
	});

	this->pluginPageResponder.reset(new PluginPageResponder(this->pluginLoader, this->cModules->getComms()));
	this->mediaStreamResponder.reset(new MediaStreamResponder(this->cModules.get()));

	ErrorLogger::logInfo("Initialised");
}

ArseholeFramework::~ArseholeFramework()
{
	delete this->pluginLoader;
}

void ArseholeFramework::process()
{
	this->cModules->getComms()->startComms("/home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/Arsehole/Framework/Static_content/");

	this->cModules->getSensors().Start(
		this->cModules->getDatabaseConnection(),
		this->cModules->getComms()->Router().get()
	);

	this->pluginLoader = new Loader("/home/Arsehole");

	ErrorLogger::logInfo("Loading Modules");
	this->loadStartupPlugins();
	ErrorLogger::logInfo("Modules Loaded");

	this->cModules->getTaskList()->StartTasks();
	this->cModules->getScheduler()->Start();
	
	processCommandLoop();

	{
        std::unique_lock<std::mutex> lk(m_shutdown_mutext);
        m_shutdown_cv.wait(lk, [&]{return shuttingDown;});
    }


	this->cModules->getComms()->stopComms();
	ErrorLogger::logInfo("Shutting down");
}

void ArseholeFramework::loadStartupPlugins()
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
	    	pluginLoader->loadPlugin(filenameStr,&mediaImages, this->cModules.get());

	    }
	  }
}


void ArseholeFramework::processDiagnosticMessage(TranslatedMessages::RequestDisagnosticsMessage* msg,
		coremodules::comms::protocals::IProtocal* protocal)
{
	std::stringstream statusMessage;

	bool dbConnection = cModules->getDatabaseConnection()->isConnected();
	statusMessage << "Database Connection{Connection Status:";
	if(dbConnection)
		statusMessage << "1";
	else
		statusMessage << "0";

	statusMessage << "},Audio Devices{";
	std::list<AudioDevice> audioDevices;
	cModules->getMediaStreamer().Get_Audio_Devices(audioDevices);
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


void ArseholeFramework::processCommandLoop()
{
	std::string command;

	struct command_t{
		std::function<void()> handler;
		std::string description;

	};

	std::map<std::string,command_t> command_list = {
		{"shutdown",{[&]{
			std::unique_lock<std::mutex> lk(m_shutdown_mutext);
			this->shuttingDown = true;
			m_shutdown_cv.notify_one();
			
		}, "Shuts down services and exits program"}},

		{"help",{
			[&]{std::cout << "Commands:" << std::endl;
				for(auto& cmd : command_list){
					std::cout << cmd.first << "\t : " << cmd.second.description << std::endl;
				}}, "displays help"}},

		{"update config",{
			[]{
			if(Config::ReadConfig("config.ini")){
				ErrorLogger::logInfo("Config updated");
			}else {
				ErrorLogger::logWarn("Config failed to update");
			}}, "Rereads the config.ini file"}},

		{"media resend_handshake",{
			[&]{this->cModules->getMediaStreamer().Resend_Agent_Handshake_Message();},
			 "Resends the Agent handshake"}},
	};

	
	while(!this->shuttingDown) {
			
		// we are using select here( which is a linux specific command) because
		// the std lib dosnt seem to have anything to support async io and we need that 
		// because we can shutdown from a seperate thread
		struct timeval tv;
		tv.tv_sec = 0;
		tv.tv_usec = 100;

		fd_set fds;
		FD_ZERO (&fds);
		FD_SET (STDIN_FILENO, &fds);

		int result = select (STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
		if (result && result != -1)
		{
			if (FD_ISSET (0, &fds))
			{
				if(!std::getline(std::cin, command)){
					ErrorLogger::logError("CLI error stopping CLI. ");
					return;
				}
			}

			std::transform(command.begin(), command.end(), command.begin(), 
                [](unsigned char c){ return std::tolower(c); }
            );
			std::cout<< command;
			if(command_list.find(command) != command_list.end()){
				
				command_list[command].handler();

			} else
			{
				ErrorLogger::logError("Unrecognised Command:" + command);
			}

		}
	}

}

