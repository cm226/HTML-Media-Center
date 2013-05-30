/*
 * EventManager.cpp
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#include "EventManager.h"



coremodules::eventmodel::events::EventSig<std::string,std::string> EventManager::onPluginViewRequest;
coremodules::eventmodel::events::EventSig<bool,int> EventManager::commandAndControlMessageReceved;
coremodules::eventmodel::events::EventSig<std::string, std::vector<std::string> > EventManager::onPluginInteractionRequest;



EventManager::EventManager() {
	// TODO Auto-generated constructor stub

}

EventManager::~EventManager() {
	// TODO Auto-generated destructor stub
}

