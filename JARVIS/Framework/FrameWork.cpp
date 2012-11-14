#include "FrameWork.h"

#include <stdio.h>

JARVISFramework::JARVISFramework()
{
	this->shuttingDown = false;

	EventManager::pluginPoll.attach(this,&JARVISFramework::loadedPlugins);
	EventManager::commandAndControlMessageReceved.attach(this,&JARVISFramework::commandAndControlMessageReceved);

	this->pluginLoader = new Loader("/var/www/HTML-Media-Center/JARVIS/Plugins");
	this->loadStartupPlugins();
}

JARVISFramework::~JARVISFramework()
{
	delete this->pluginLoader;
}

void JARVISFramework::testEvents()
{
	bool (listenerClass::*member)(int) = &listenerClass::testHandler;
	Event<bool,int> testEvent;
	listenerClass* testList = new listenerClass;


	CppEventHandler h = testEvent.attach<listenerClass>(testList,member);

	//testEvent.notify(100);

	testEvent.detach(h);

	delete testList;

}

void JARVISFramework::testPlugins()
{



}

void JARVISFramework::testComms()
{
	Comms coms;

	coms.startComms();
	sleep(100); // give 100 seconds to establish and test comms
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

bool listenerClass::testHandler(int t)
{
	printf("hfdjks %i",t);
	return false;
}


