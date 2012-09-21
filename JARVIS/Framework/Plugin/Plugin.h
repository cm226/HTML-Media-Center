/*
 * Plugin.h
 *
 *  Created on: Sep 4, 2012
 *      Author: craig
 */

#ifndef PLUGIN_H_
#define PLUGIN_H_

#include "../FrameWork.h"

class Plugin {

	JARVISFramework* frameWork;

public:
	Plugin(JARVISFramework* framework);

	virtual bool whatDoYouLookLike(Page*) = 0;
	virtual ~Plugin();

};

#endif /* PLUGIN_H_ */
