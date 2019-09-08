/*
 * DatabaseInterfaceGenerator.h
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#ifndef DATABASEINTERFACEGENERATOR_H_
#define DATABASEINTERFACEGENERATOR_H_


#include "../../arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "DatabaseInterfaceGeneratorPlugin.h"


DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new DatabaseInterfaceGeneratorPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}


#endif /* DATABASEINTERFACEGENERATOR_H_ */
