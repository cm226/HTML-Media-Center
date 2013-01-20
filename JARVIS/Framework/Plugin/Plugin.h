/*
 * Plugin.h
 *
 *  Created on: Sep 4, 2012
 *      Author: craig
 */

#ifndef PLUGIN_H_
#define PLUGIN_H_

#include "../CoreModules/CoreModules.h"

class Plugin {

protected:
	CoreModules* coreMod;

public:
	Plugin(CoreModules* coreMod);

	virtual bool whatDoYouLookLike(Page*) = 0;
	virtual const char* pluginName() = 0;
	virtual ~Plugin();

};

#endif /* PLUGIN_H_ */
