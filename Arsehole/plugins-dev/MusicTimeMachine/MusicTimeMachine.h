/*
 * MusicTimeMachine.h
 *
 *  Created on: 23 Jul 2013
 *      Author: craig
 */

#ifndef MUSICTIMEMACHINE_H_
#define MUSICTIMEMACHINE_H_

#include "../../arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "MusicTimeMachinePlugin.h"



DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new MusicTimeMachinePlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}

#endif /* MUSICTIMEMACHINE_H_ */
