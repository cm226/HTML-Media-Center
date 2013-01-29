#include "FrameWork.h"

#include <stdio.h>
#include <boost/thread.hpp>
#include <sstream>

JARVISFramework::JARVISFramework()
{
	this->shuttingDown = false;

	EventManager::pluginPoll.attach(this,&JARVISFramework::loadedPlugins);
	EventManager::commandAndControlMessageReceved.attach(this,&JARVISFramework::commandAndControlMessageReceved);
	EventManager::onPluginViewRequest.attach(this,&JARVISFramework::getPluginPage);
	EventManager::onPluginInteractionRequest.attach(this,&JARVISFramework::pluginInteractionRequest);


#ifdef _WINDOWS
	this->pluginLoader = new Loader("C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\plugins");
#else
	this->pluginLoader = new Loader("/var/www/HTML-Media-Center/JARVIS/Plugins");
#endif
	this->loadStartupPlugins();
}

JARVISFramework::~JARVISFramework()
{
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
	ErrorLogger::logError("Shutting down");
}

void JARVISFramework::loadStartupPlugins()
{
	Plugin* emailChecker = NULL;
	Plugin* mediaImages = NULL;

	//pluginLoader->loadPlugin("libEmailChecker",&emailChecker, &this->cModules);
	pluginLoader->loadPlugin("libMediaImages",&mediaImages, &this->cModules);

}

std::vector<std::string> JARVISFramework::loadedPlugins(int i)
{
	std::vector<std::string> loadedPlugins;
	this->pluginLoader->listLoadedPlugins(&loadedPlugins);
	return loadedPlugins;
}

void JARVISFramework::processCommandLoop()
{
	std::string command;
	while(!this->shuttingDown)
	{
		std::cin >> command;
			if(command == "shutdown")
					this->shuttingDown = true;
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


