/*
 * Loader.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: craig
 */

#include "Loader.h"

#include "../../../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"
#include <stdio.h>
#include <sys/types.h>

#include <string>
#include <cstring>

#ifdef _WINDOWS
#include <windows.h> 
#else
#include <dirent.h>
#include <dlfcn.h>
#endif

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

	ErrorLogger::logInfo("Loading plugin: "+pluginName);
	

#ifdef _WINDOWS

	std::string libfileNamestr = (this->pluginDir + "\\" + pluginName + ".dll").c_str();
	const char* libfileName = libfileNamestr.c_str();
	typedef Plugin* (__cdecl *MYPROC)(CoreModules*); 
	HINSTANCE hinstLib;
	MYPROC ProcAdd; 
	hinstLib = LoadLibrary(TEXT(libfileName)); 

	if (hinstLib != NULL) 
    { 
        ProcAdd = (MYPROC) GetProcAddress(hinstLib, "makePlugin"); 
 
        // If the function address is valid, call the function.
 
        if (NULL != ProcAdd) 
        {
            *loadedPlugin= static_cast<Plugin*>((ProcAdd) (context)); 
			this->dllHandlPluginMap[*loadedPlugin] = hinstLib;
			return true;
        }
        // Free the DLL module.
 
        
    } 

	ErrorLogger::logError(std::string("Error Loading plugin"));
	return false;



#else
	
	const char* libfileName = (this->pluginDir + "/" + pluginName + ".so").c_str();
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
#endif
}

bool Loader::unloadPlugin(Plugin* plugin)
{
	if(this->dllHandlPluginMap.find(plugin) == this->dllHandlPluginMap.end())
		return false;

#ifdef _WINDOWS

	void* handl = this->dllHandlPluginMap[plugin];
	return  FreeLibrary((HINSTANCE)handl) == TRUE; 

#else

	void* handl = this->dllHandlPluginMap[plugin];
	unload unloadFunc;
	*(void**)(&unloadFunc) = dlsym(handl,"releasePlugin");
	return unloadFunc(plugin);
#endif
}

void Loader::listPlugins(std::vector<std::string>* outBuffer)
{
#ifdef _WINDOWS

#else
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
#endif
}

void Loader::listLoadedPlugins(std::vector<std::string>* outBuffer)
{
	for(std::map<Plugin*,void *>::iterator it = this->dllHandlPluginMap.begin(); it != this->dllHandlPluginMap.end(); it++)
	{
		outBuffer->push_back((*it).first->pluginName());
	}
}

Plugin* Loader::getPluginByName(std::string pluginName)
{
	for(std::map<Plugin*,void *>::iterator it = this->dllHandlPluginMap.begin(); it != this->dllHandlPluginMap.end(); it++)
		{
			std::string name = std::string((*it).first->pluginName());
			int cmpVal = strcmp(name.c_str(), pluginName.c_str());
			if(cmpVal==0)
				return ((*it).first);
		}

	ErrorLogger::logError("Failed to get plugin by name: "+pluginName);
	return NULL;
}

