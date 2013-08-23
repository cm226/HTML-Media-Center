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

#include "../../JARVISCoreModules/CoreModules/CoreModules.h"
#include "Plugin/Loader/Loader.h"
#include "PluginPageResponder.h"
#include "MediaStreamResponder.h"

#include "../../JARVISCoreModules/CoreModules/Comms/Protocals/IProtocal.h"
#include <boost/scoped_ptr.hpp>

class JARVISFramework
{
private:
	Loader* pluginLoader;
	boost::scoped_ptr<PluginPageResponder> pluginPageResponder;
	boost::scoped_ptr<MediaStreamResponder> mediaStreamResponder;

	CoreModules cModules;


	bool shuttingDown;
	CppEventHandler ppEventHandler;
	CppEventHandler cAndcEventHandler;
	CppEventHandler ViewReqEventHandler;
	CppEventHandler interactionReqEventHandler;

public:
	JARVISFramework();
	virtual ~JARVISFramework();

	void process();

private:
	void loadedPlugins(ListPluginsMessage*, coremodules::comms::protocals::IProtocal*);

	void loadStartupPlugins();
	bool commandAndControlMessageReceved(int type);

	void processCommandLoop();

};


#endif /* FRAMEWORK_H_ */
