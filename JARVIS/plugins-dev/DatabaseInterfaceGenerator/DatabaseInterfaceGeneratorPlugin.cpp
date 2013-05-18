/*
 * DatabaseInterfaceGeneratorPlugin.cpp
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#include "DatabaseInterfaceGeneratorPlugin.h"

DatabaseInterfaceGeneratorPlugin::DatabaseInterfaceGeneratorPlugin(CoreModules* cm) : Plugin(cm)
{
}

DatabaseInterfaceGeneratorPlugin::~DatabaseInterfaceGeneratorPlugin()
{

}

bool whatDoYouLookLike(Page*)
{

	return true;
}
const char* pluginName()
{
	return "Database Interface Generator";
}

