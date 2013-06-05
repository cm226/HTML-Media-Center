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

#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ListPluginsMessage.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginPageMessage.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginInteractionRequestMessage.h"

#include "../../JARVISCoreModules/CoreModules/Comms/Protocals/IProtocal.h"

class JARVISFramework
{
private:
	Loader* pluginLoader;
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
	void pluginPageRequestHandler(TranslatedMessages::PluginPageMessage*, coremodules::comms::protocals::IProtocal*);

	void pluginInteractionRequestHandler(TranslatedMessages::PluginInteractionRequestMessage* msg, coremodules::comms::protocals::IProtocal* p);

	void loadStartupPlugins();
	bool commandAndControlMessageReceved(int type);

	void processCommandLoop();

};


#endif /* FRAMEWORK_H_ */
