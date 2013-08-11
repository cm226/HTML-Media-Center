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

	std::string page = "";
	std::string pluginName(msg->pluginName());

	Plugin* plugin = this->pluginLoader->getPluginByName(pluginName);
	if(plugin != NULL)
	{
		Page pluginPage;
		plugin->whatDoYouLookLike(&pluginPage);

		pluginPage.buildPage(&page);
		pluginPage.freePage();
	}

	protocal->sendMessage(new TranslatedMessages::ReplyMessage(page));
}

void PluginPageResponder::mobilePluginPageRequestHandler(TranslatedMessages::MobilePluginPageMessage* msg, coremodules::comms::protocals::IProtocal* protocal)
{
	std::string page = "";
	std::string pluginName(msg->pluginName());

	Plugin* plugin = this->pluginLoader->getPluginByName(pluginName);
	if(plugin != NULL)
	{
		Page pluginPage;
		plugin->whatDoYouLookLike(&pluginPage);

		pluginPage.buildMobilePage(&page);
		pluginPage.freePage();
	}

	protocal->sendMessage(new TranslatedMessages::ReplyMessage(page));

}

void PluginPageResponder::pluginInteractionRequestHandler(TranslatedMessages::PluginInteractionRequestMessage* msg, coremodules::comms::protocals::IProtocal* protocal)
{
	Plugin* p = this->pluginLoader->getPluginByName(msg->pluginName);
	Page page;
	PageCallbackContext pcContext;

	std::vector<std::string> contextVals(msg->contextValues.begin(), msg->contextValues.end());
	pcContext.setAdditionalContext(&contextVals);
	std::istringstream buffer(msg->callbackID);

	CALLBACk_HANDLE callbackHandl;
	buffer >> callbackHandl;

	pcContext.callbackHandle = callbackHandl;
	std::string sPage;
	if(!p->notifyPageCallback(&page,&pcContext))
	{
		ErrorLogger::logError("failed to call plugin callback");
		sPage = "Plugin error not enough data see JARVIS log for more";
	}


	page.buildPage(&sPage);
	page.freePage();


	protocal->sendMessage(new TranslatedMessages::ReplyMessage(sPage));
}


