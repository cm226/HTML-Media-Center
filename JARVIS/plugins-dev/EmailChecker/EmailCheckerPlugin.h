/*
 * EmailCheckerPlugin.h
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#ifndef EMAILCHECKERPLUGIN_H_
#define EMAILCHECKERPLUGIN_H_

#include "../../JARVIS/Framework/Plugin/Plugin.h"
#include <string>


class EmailCheckerPlugin : public Plugin{
private:
	std::string name;

public:
	EmailCheckerPlugin(CoreModules* framework);
	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
	virtual ~EmailCheckerPlugin();
};

#endif /* EMAILCHECKERPLUGIN_H_ */
