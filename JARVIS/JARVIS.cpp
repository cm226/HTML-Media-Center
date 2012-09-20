
#include <stdio.h>

#include "Framework/Plugin/Loader/Loader.h"
int main()
{
	Loader pluginLoader("/home/craig/workspace/HTML-Media-Center/JARVIS/Plugins");

	int numOfPlugins = pluginLoader.numOfPlugins();

	return 0;
}
