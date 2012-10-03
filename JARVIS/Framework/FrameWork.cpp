#include "FrameWork.h"

#include <stdio.h>

JARVISFramework::JARVISFramework()
{

	EventManager::pluginPoll.attach(this,&JARVISFramework::loadedPlugins);

	this->pluginLoader = new Loader("/home/craig/workspace/HTML-Media-Center/JARVIS/Plugins");
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

bool listenerClass::testHandler(int t)
{
	printf("hfdjks %i",t);
	return false;
}


