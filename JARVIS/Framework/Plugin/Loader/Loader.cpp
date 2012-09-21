/*
 * Loader.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: craig
 */

#include "Loader.h"

#include "../../Errors/ErrorLogger.h"
#include <sys/types.h>
#include <dirent.h>

Loader::Loader(std::string pluginDir) {
	this->pluginDir = pluginDir;
}

Loader::~Loader() {
	// TODO Auto-generated destructor stub
}

bool Loader::loadPlugin(std::string pluginName, Plugin* loadedPlugin)
{
	/*void *hndl = dlopen("libnewshapes.so", RTLD_NOW);

	if(hndl == NULL)
	{
		ErrorLogger::logError("Error Loading plugin: "+dlerror());
	}
	void *mkr = dlsym(hndl, "maker");
	loadedPlugin= static_cast<Plugin *()>(mkr)();*/

	return true;
}

void Loader::listPlugins(std::vector<std::string>* outBuffer)
{
	    DIR *dp;
	    struct dirent *dirp;
	    if((dp  = opendir(this->pluginDir.c_str())) == NULL)
	    {
	    	ErrorLogger::logError("Unable to open plugins Directory");
	        return;
	    }

	    while ((dirp = readdir(dp)) != NULL) {
	    	outBuffer->push_back(std::string(dirp->d_name));
	    }
	    closedir(dp);
	    return;

}
