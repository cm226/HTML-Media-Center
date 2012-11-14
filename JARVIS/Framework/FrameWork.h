/*
 * FrameWork.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include <vector>
#include <string>

#include "CoreModules/CoreModules.h"
#include "Plugin/Loader/Loader.h"

class JARVISFramework
{
	Loader* pluginLoader;
	CoreModules cModules;

	bool shuttingDown;

public:
	JARVISFramework();
	virtual ~JARVISFramework();

	void testComms();

private:
	std::vector<std::string> loadedPlugins(int i);
	std::string getPluginPage(std::string pluginName);

	void loadStartupPlugins();
	bool commandAndControlMessageReceved(int type);

};

class listenerClass
{
public:
	bool testHandler(int i);
};

#endif /* FRAMEWORK_H_ */
