/*
 * EventManager.h
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include "Events/Event.h"
#include <string>
#include <vector>
#include "../exportMacros.h"

class DLLCORE_API EventManager {
public:

	static Event<std::vector<std::string>,int> pluginPoll;
	static Event<std::string,std::string> onPluginViewRequest;
	static Event<std::string, std::vector<std::string> > onPluginInteractionRequest;

	static Event<bool,int> commandAndControlMessageReceved;

	EventManager();
	virtual ~EventManager();
};

#endif /* EVENTMANAGER_H_ */
