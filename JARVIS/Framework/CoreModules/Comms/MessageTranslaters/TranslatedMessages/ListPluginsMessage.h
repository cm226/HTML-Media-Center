/*
 * ListPluginsMessage.h
 *
 *  Created on: Oct 3, 2012
 *      Author: craig
 */

#ifndef LISTPLUGINSMESSAGE_H_
#define LISTPLUGINSMESSAGE_H_

#include "AbstractMessage.h"

class ListPluginsMessage: public AbstractMessage {
public:
	ListPluginsMessage(const char* data, unsigned int length);
	virtual ~ListPluginsMessage();

	void actionMessage(std::string* reply,EventManager* evntman);
};

#endif /* LISTPLUGINSMESSAGE_H_ */
