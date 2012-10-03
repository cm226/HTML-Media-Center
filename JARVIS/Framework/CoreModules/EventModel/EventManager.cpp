/*
 * EventManager.cpp
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#include "EventManager.h"

Event<std::vector<std::string>,int> EventManager::pluginPoll;
Event<std::string,int> EventManager::onPluginViewRequest;


EventManager::EventManager() {
	// TODO Auto-generated constructor stub

}

EventManager::~EventManager() {
	// TODO Auto-generated destructor stub
}

