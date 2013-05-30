/*
 * Plugin.h
 *
 *  Created on: Sep 4, 2012
 *      Author: craig
 */

#ifndef PLUGIN_H_
#define PLUGIN_H_

#include "../../../JARVISCoreModules/CoreModules/CoreModules.h"
#include "PageCallbackContext.h"

#include <boost/function.hpp>
#include <map>
#include <array>
#include "../../../JARVISCoreModules/CoreModules/HTMLRendere/Page.h"
#include "../../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"
#include <exception>
#include "HTMLCALLBACKDef.h"

class Plugin {
public:
	enum pluginGroup{MISC, MUSIC, MOVIE, TV, CONTENT_GEN, PROG};

private:
	CALLBACk_HANDLE nextFreeCallbackHandle;
	std::map<CALLBACk_HANDLE, boost::function2<bool ,Page*,PageCallbackContext* > > pageCallbacks;
	

protected:
	CoreModules* coreMod;
	pluginGroup myGroup;

public:
	Plugin(CoreModules* coreMod) : myGroup(MISC)
	{
		nextFreeCallbackHandle = 0;
		this->coreMod = coreMod;
	};

	pluginGroup pluginGroup(){return this->myGroup;};
	bool notifyPageCallback(Page* page, PageCallbackContext* context)
	{
		if(this->pageCallbacks.find(context->callbackHandle) != this->pageCallbacks.end())
			return this->pageCallbacks[context->callbackHandle](page, context);

		ErrorLogger::logError("page callback just called for unregistered handle");

	#ifdef _DEBUG
		throw std::runtime_error("unregistered callback called in HTML callbacks");
	#endif

		return false;
	};
	CALLBACk_HANDLE subscribeHTMLCallback(boost::function2<bool ,Page*,PageCallbackContext* > callbk)
	{
		CALLBACk_HANDLE hndl = nextFreeCallbackHandle;
		nextFreeCallbackHandle++;

		this->pageCallbacks[hndl] = callbk;
		return hndl;
	}

	virtual bool whatDoYouLookLike(Page*) = 0;
	virtual const char* pluginName() = 0;
	virtual ~Plugin(){};

};

#endif /* PLUGIN_H_ */
