/*
 * PluginPageResponder.cpp
 *
 *  Created on: 30 Jul 2013
 *      Author: craig
 */

#include "PluginPageResponder.h"

PluginPageResponder::PluginPageResponder(Loader* pluginLoader, CommsNS::IComms* comms) : pluginLoader(pluginLoader)
{
	comms->messagesubject()->onPluginPageMessageReceved.connect(this, &PluginPageResponder::pluginPageRequestHandler);
	comms->messagesubject()->onMobilePluginPageMessageReceved.connect(this, &PluginPageResponder::mobilePluginPageRequestHandler);
	comms->messagesubject()->onPluginInteractionMessageReceved.connect(this,&PluginPageResponder::pluginInteractionRequestHandler);
}

PluginPageResponder::~PluginPageResponder()
{

}

void PluginPageResponder::pluginPageRequestHandler(TranslatedMessages::PluginPageMessage* msg, coremodules::comms::protocals::IProtocal* protocal)
{
	// dead
}

void PluginPageResponder::mobilePluginPageRequestHandler(TranslatedMessages::MobilePluginPageMessage* msg, coremodules::comms::protocals::IProtocal* protocal)
{
	// dead
}

void PluginPageResponder::pluginInteractionRequestHandler(TranslatedMessages::PluginInteractionRequestMessage* msg, coremodules::comms::protocals::IProtocal* protocal)
{
	// dead
}


