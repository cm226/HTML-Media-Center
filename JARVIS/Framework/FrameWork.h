/*
 * FrameWork.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include "CoreModules/CoreModules.h"
#include "Plugin/Loader/Loader.h"

class JARVISFramework
{
public:
	JARVISFramework();
	virtual ~JARVISFramework(){}

	void testPlugins();
	void testEvents();

};

class listenerClass
{
public:
	bool testHandler(int i);
};

#endif /* FRAMEWORK_H_ */
