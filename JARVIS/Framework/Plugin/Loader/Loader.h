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

#include "../Plugin.h"

class Loader {
private:
	std::string pluginDir;


public:
	Loader(std::string fileDir);

	bool loadPlugin(std::string pluginName, Plugin* loadedPlugin);

	void listPlugins(std::vector<std::string>* outBuffer);

	virtual ~Loader();
};

#endif /* LOADER_H_ */
