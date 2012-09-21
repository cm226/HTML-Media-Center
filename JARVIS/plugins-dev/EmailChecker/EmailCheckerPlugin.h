/*
 * EmailCheckerPlugin.h
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#ifndef EMAILCHECKERPLUGIN_H_
#define EMAILCHECKERPLUGIN_H_

#include "../../Framework/Plugin/Plugin.h"

class EmailCheckerPlugin : public Plugin{
public:
	EmailCheckerPlugin(JARVISFramework* framework);
	virtual bool whatDoYouLookLike(Page*);
	virtual ~EmailCheckerPlugin();
};

#endif /* EMAILCHECKERPLUGIN_H_ */
