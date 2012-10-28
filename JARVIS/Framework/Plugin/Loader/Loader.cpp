/*
 * Loader.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: craig
 */

#include "Loader.h"

#include "../../CoreModules/Errors/ErrorLogger.h"
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>
#include <string>



#include "../IPluginDLLFactory.h"

typedef void* (*arbitrary)(CoreModules*); // need to read up on my c++ to get this to work proper
typedef bool (*unload)(Plugin*);

Loader::Loader(std::string pluginDir)
{
	this->pluginDir = pluginDir;
}

Loader::~Loader()
{
	// cleanup loaded plugins
	for(std::map<Plugin*,void *>::iterator it = this->dllHandlPluginMap.begin(); it != this->dllHandlPluginMap.end(); it++)
	{
		this->unloadPlugin(it->first);
	}
}

bool Loader::loadPlugin(std::string pluginName, Plugin** loadedPlugin, CoreModules* context)
{
	const char* libfileName = this->pluginDir.append("/").append(pluginName).append(".so").c_str();

	void *hndl = dlopen(libfileName, RTLD_NOW);
	arbitrary factoryFunc;

	if(hndl == NULL)
	{
		ErrorLogger::logError(std::string("Error Loading plugin: ").append(dlerror()));
		return false;
	}

	*(void**)(&factoryFunc) = dlsym(hndl,"makePlugin");

	*loadedPlugin= static_cast<Plugin*>(factoryFunc(context));
	this->dllHandlPluginMap[*loadedPlugin] = hndl;
	return true;
}

bool Loader::unloadPlugin(Plugin* plugin)
{
	if(this->dllHandlPluginMap.find(plugin) == this->dllHandlPluginMap.end())
		return false;

	void* handl = this->dllHandlPluginMap[plugin];
	unload unloadFunc;
	*(void**)(&unloadFunc) = dlsym(handl,"releasePlugin");
	return unloadFunc(plugin);

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

void Loader::listLoadedPlugins(std::vector<std::string>* outBuffer)
{
	for(std::map<Plugin*,void *>::iterator it = this->dllHandlPluginMap.begin(); it != this->dllHandlPluginMap.end(); it++)
	{
		outBuffer->push_back((*it).first->pluginName());
	}
}
