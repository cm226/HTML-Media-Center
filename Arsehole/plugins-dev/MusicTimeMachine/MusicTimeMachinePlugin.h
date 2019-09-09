/*
 * MusicTimeMachinePlugin.h
 *
 *  Created on: 23 Jul 2013
 *      Author: craig
 */

#ifndef MUSICTIMEMACHINEPLUGIN_H_
#define MUSICTIMEMACHINEPLUGIN_H_

#include "../../Arsehole/Framework/Plugin/Plugin.h"


class MusicTimeMachinePlugin : public Plugin
{
public:
	MusicTimeMachinePlugin(CoreModules* cm);
	virtual ~MusicTimeMachinePlugin();

	bool whatDoYouLookLike(Page*);
	const char* pluginName();
};

#endif /* MUSICTIMEMACHINEPLUGIN_H_ */
