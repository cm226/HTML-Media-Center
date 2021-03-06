/*
 * Loader.h
 *
 *  Created on: Sep 20, 2012
 *      Author: craig
 */

#ifndef LOADER_H_
#define LOADER_H_

#include <string>
#include <vector>
#include <map>

#include "../Plugin.h"
#include "../../../../ArseholeCoreModules/CoreModules/CoreModules.h"


class Loader {
private:
	std::string pluginDir;
	std::map<Plugin*,void *> dllHandlPluginMap;

public:
	Loader(std::string fileDir);

	bool loadPlugin(std::string pluginName, Plugin** loadedPlugin, CoreModules* context);
	bool unloadPlugin(Plugin* plugin);

	void listPlugins(std::vector<std::string>* outBuffer);
	
	void listLoadedPlugins(std::vector<Plugin*>* outBuffer);
	void listLoadedPlugins(std::vector<std::string>* outBuffer);

	Plugin* getPluginByName(std::string pluginName);

	std::string PluginDir() {return pluginDir;}
	virtual ~Loader();
};

#endif /* LOADER_H_ */
