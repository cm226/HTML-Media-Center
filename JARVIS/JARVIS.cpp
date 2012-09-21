
#include <stdio.h>


#include "Framework/Plugin/Loader/Loader.h"
int main()
{
	Loader pluginLoader("/home/craig/workspace/HTML-Media-Center/JARVIS/Plugins");

	std::vector<std::string> files;
	pluginLoader.listPlugins(&files);


	return 0;
}
