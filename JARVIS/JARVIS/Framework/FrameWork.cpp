#include "FrameWork.h"

#include <stdio.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <sstream>
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.h"
#include <list>

#ifdef _WINDOWS
#include <Windows.h>
#endif

JARVISFramework::JARVISFramework()
{
	ErrorLogger::logInfo("JARVIS initalising...");
	this->shuttingDown = false;

	this->cModules.getComms()->messagesubject()->onListPluginsMessageReceved.connect(this, &JARVISFramework::loadedPlugins);

	EventManager::commandAndControlMessageReceved.attach(this,&JARVISFramework::commandAndControlMessageReceved);
	EventManager::onPluginViewRequest.attach(this,&JARVISFramework::getPluginPage);
	EventManager::onPluginInteractionRequest.attach(this,&JARVISFramework::pluginInteractionRequest);


#ifdef _WINDOWS
	this->pluginLoader = new Loader("C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\plugins");
#else
	this->pluginLoader = new Loader("/var/www/HTML-Media-Center/JARVIS/Plugins");
#endif

	ErrorLogger::logInfo("Loading Modules");
	this->loadStartupPlugins();
	ErrorLogger::logInfo("Modules Loaded");
}

JARVISFramework::~JARVISFramework()
{
	// TODO this is fucked up on windows, change to boost signals lib
	/*EventManager::pluginPoll.detach(ppEventHandler);
	EventManager::commandAndControlMessageReceved.detach(cAndcEventHandler);
	EventManager::onPluginViewRequest.detach(ViewReqEventHandler);
	EventManager::onPluginInteractionRequest.detach(interactionReqEventHandler);*/

	delete this->pluginLoader;

}



void JARVISFramework::process()
{
	this->cModules.getComms()->startComms();
	boost::thread listenForConnectionThread(boost::bind(&JARVISFramework::processCommandLoop, this));

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
	Plugin* mediaImages = NULL;

	pluginLoader->loadPlugin("libMediaImages",&mediaImages, &this->cModules);
	pluginLoader->loadPlugin("libDatabaseInterfaceGenerator",&mediaImages, &this->cModules);
	pluginLoader->loadPlugin("LogViewer",&mediaImages, &this->cModules);

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
	while(!this->shuttingDown)
	{
		std::cin >> command;
			if(command == "shutdown")
			{
					this->shuttingDown = true;
					return;
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

std::string JARVISFramework::getPluginPage(std::string pluginName)
{
	std::string page = "";
	Plugin* plugin = this->pluginLoader->getPluginByName(pluginName);
	if(plugin != NULL)
	{
		Page pluginPage;
		plugin->whatDoYouLookLike(&pluginPage);

		pluginPage.buildPage(&page);
		pluginPage.freePage();
	}
	return page;

}

std::string JARVISFramework::pluginInteractionRequest(std::vector<std::string> context)
{
	if(context.size() < 2)
	{
		ErrorLogger::logError("plugin context dont contain enuf information to process them need callback ID and pluginName");
		return "Plugin error not enough data see JARVIS log for more";
	}

	std::string callbackID = *context.begin();
	context.erase(context.begin());
	std::string pluginName = *context.begin();
	context.erase(context.begin());

	Plugin* p = this->pluginLoader->getPluginByName(pluginName);
	Page page;
	PageCallbackContext pcContext;
	
	pcContext.setAdditionalContext(&context);
	std::istringstream buffer(callbackID);
	CALLBACk_HANDLE callbackHandl;
	buffer >> callbackHandl; 

	pcContext.callbackHandle = callbackHandl;

	if(!p->notifyPageCallback(&page,&pcContext))
	{
		ErrorLogger::logError("failed to call plugin callback");
		return "Plugin error not enough data see JARVIS log for more";
	}

	std::string sPage;
	page.buildPage(&sPage);
	page.freePage();

	return sPage;
}


