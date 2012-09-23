#include "FrameWork.h"


#include <stdio.h>

JARVISFramework::JARVISFramework()
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

