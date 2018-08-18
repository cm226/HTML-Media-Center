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
#include "../../../ErrorLogger/Errors/ErrorLogger.h"
#include <exception>
#include "HTMLCALLBACKDef.h"

class Plugin {
public:
	enum pluginGroup{MISC, MUSIC, MOVIE, TV, CONTENT_GEN, PROG};


protected:
	CoreModules* coreMod;
	pluginGroup myGroup;

public:
	Plugin(CoreModules* coreMod) : myGroup(MISC)
	{
		this->coreMod = coreMod;
	};

	pluginGroup pluginGroup(){return this->myGroup;};
	
	virtual void handleRequest(std::string requestURL) = 0;
	virtual const std::string pluginName() = 0;
	virtual ~Plugin(){};

};

#endif /* PLUGIN_H_ */
