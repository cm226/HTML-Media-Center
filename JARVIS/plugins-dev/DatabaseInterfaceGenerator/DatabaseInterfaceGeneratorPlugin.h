/*
 * DatabaseInterfaceGeneratorPlugin.h
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#ifndef DATABASEINTERFACEGENERATORPLUGIN_H_
#define DATABASEINTERFACEGENERATORPLUGIN_H_

#include "../../JARVIS/Framework/Plugin/Plugin.h"

class DatabaseInterfaceGeneratorPlugin : public Plugin
{
private:


public:
	DatabaseInterfaceGeneratorPlugin(CoreModules* cm);
	virtual ~DatabaseInterfaceGeneratorPlugin();

	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
};

#endif /* DATABASEINTERFACEGENERATORPLUGIN_H_ */
