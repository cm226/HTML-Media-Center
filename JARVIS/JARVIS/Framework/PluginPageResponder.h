/*
 * PluginPageResponder.h
 *
 *  Created on: 30 Jul 2013
 *      Author: craig
 */

#ifndef PLUGINPAGERESPONDER_H_
#define PLUGINPAGERESPONDER_H_

#include "../../JARVISCoreModules/CoreModules/CoreModules.h"
#include "Plugin/Loader/Loader.h"

#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ListPluginsMessage.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginPageMessage.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/MobilePluginPageMessage.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginInteractionRequestMessage.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.h"

#include "../../JARVISCoreModules/CoreModules/Comms/Protocals/IProtocal.h"


class PluginPageResponder {
public:
	PluginPageResponder(Loader* pluginLoader, CommsNS::IComms* comms);
	virtual ~PluginPageResponder();

private:
	Loader* pluginLoader;

	void pluginPageRequestHandler(TranslatedMessages::PluginPageMessage*, coremodules::comms::protocals::IProtocal*);
	void mobilePluginPageRequestHandler(TranslatedMessages::MobilePluginPageMessage*, coremodules::comms::protocals::IProtocal*);

	void pluginInteractionRequestHandler(TranslatedMessages::PluginInteractionRequestMessage* msg, coremodules::comms::protocals::IProtocal* p);
};

#endif /* PLUGINPAGERESPONDER_H_ */
