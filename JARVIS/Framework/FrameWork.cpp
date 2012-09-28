#include "FrameWork.h"


#include <stdio.h>

JARVISFramework::JARVISFramework()
{



}

void JARVISFramework::testEvents()
{
	bool (listenerClass::*member)(int) = &listenerClass::testHandler;
	Event<bool,int> testEvent;
	listenerClass* testList = new listenerClass;


	CppEventHandler h = testEvent.attach<listenerClass>(testList,member);

	testEvent.notify(100);

	testEvent.detach(h);

	delete testList;

}

void JARVISFramework::testPlugins()
{

		Loader pluginLoader("/home/craig/workspace/HTML-Media-Center/JARVIS/Plugins");
		CoreModules modules;
		Page page;
		std::string pageData;

		std::vector<std::string> files;
		pluginLoader.listPlugins(&files);

		Plugin* emailChecker = NULL;

		pluginLoader.loadPlugin("libEmailChecker",&emailChecker, &modules);
		emailChecker->whatDoYouLookLike(&page);

		page.buildPage(&pageData);

		printf(pageData.c_str());

		page.freePage();
		pluginLoader.unloadPlugin(emailChecker);


}

bool listenerClass::testHandler(int t)
{
	printf("hfdjks %i",t);
	return false;
}


