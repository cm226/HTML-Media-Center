/*
 * EventManager.h
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include "Events/Event.h"
#include "Events/EventSig.h"
#include <string>
#include <vector>
#include "../exportMacros.h"

#include <boost/signal.hpp>
#include <boost/bind.hpp>


class DLLCORE_API EventManager {
private:

public:

	static coremodules::eventmodel::events::EventSig<std::string, std::vector<std::string> > onPluginInteractionRequest;
	static coremodules::eventmodel::events::EventSig<bool,int> commandAndControlMessageReceved;


	EventManager();
	virtual ~EventManager();
};

#endif /* EVENTMANAGER_H_ */
