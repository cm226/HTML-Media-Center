#include "FrameWork.h"

#include <stdio.h>

JARVISFramework::JARVISFramework()
{
	this->shuttingDown = false;

	EventManager::pluginPoll.attach(this,&JARVISFramework::loadedPlugins);
	EventManager::commandAndControlMessageReceved.attach(this,&JARVISFramework::commandAndControlMessageReceved);
	EventManager::onPluginViewRequest.attach(this,&JARVISFramework::getPluginPage);

	this->pluginLoader = new Loader("/var/www/HTML-Media-Center/JARVIS/Plugins");
	this->loadStartupPlugins();
}

JARVISFramework::~JARVISFramework()
{
	delete this->pluginLoader;
}



void JARVISFramework::testComms()
{
	Comms coms;

	coms.startComms();
	sleep(1000); // give 100 seconds to establish and test comms
	coms.stopComms();
}

void JARVISFramework::loadStartupPlugins()
{
	Plugin* emailChecker = NULL;
	pluginLoader->loadPlugin("libEmailChecker",&emailChecker, &this->cModules);
}

std::vector<std::string> JARVISFramework::loadedPlugins(int i)
{
	std::vector<std::string> loadedPlugins;
	this->pluginLoader->listLoadedPlugins(&loadedPlugins);
	return loadedPlugins;
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


