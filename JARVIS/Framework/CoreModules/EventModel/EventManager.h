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

class EventManager {
public:

	static Event<std::vector<std::string>,int> pluginPoll;
	static Event<std::string,int> onPluginViewRequest;

	static Event<bool,int> commandAndControlMessageReceved;

	EventManager();
	virtual ~EventManager();
};

#endif /* EVENTMANAGER_H_ */
