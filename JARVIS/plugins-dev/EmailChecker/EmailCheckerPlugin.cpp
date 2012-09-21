/*
 * EmailCheckerPlugin.cpp
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#include "EmailCheckerPlugin.h"

#include <stdio.h>

EmailCheckerPlugin::EmailCheckerPlugin(JARVISFramework* framework): Plugin(framework) {
	// TODO Auto-generated constructor stub

}

EmailCheckerPlugin::~EmailCheckerPlugin() {
	// TODO Auto-generated destructor stub
}

bool EmailCheckerPlugin::whatDoYouLookLike(Page* page)
{
	printf("IT WORKED");
	return true;
}
