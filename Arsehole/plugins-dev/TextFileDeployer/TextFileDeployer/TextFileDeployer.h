#pragma once
/*
 * TextFileDeployer.h
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#ifndef TEXTFILEDEPLOYER_H_
#define TEXTFILEDEPLOYER_H_


#include "../../../arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "TextFileDeployerPlugin.h"


DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new TextFileDeployerPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}


#endif /* DATABASEINTERFACEGENERATOR_H_ */
