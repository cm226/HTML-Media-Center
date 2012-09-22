#include "FrameWork.h"

JARVISFramework::JARVISFramework()
{
	Loader pluginLoader("/home/craig/workspace/HTML-Media-Center/JARVIS/Plugins");
	CoreModules modules;
	Page page;

	std::vector<std::string> files;
	pluginLoader.listPlugins(&files);

	Plugin* emailChecker = NULL;

	pluginLoader.loadPlugin("libEmailChecker",&emailChecker, &modules);
	emailChecker->whatDoYouLookLike(&page);

	pluginLoader.unloadPlugin(emailChecker);


}

