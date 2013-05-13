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
	ListPluginsMessage(char* data, unsigned int length);
	ListPluginsMessage();
	virtual ~ListPluginsMessage();

	AbstractMessage* actionMessage();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

#endif /* LISTPLUGINSMESSAGE_H_ */
