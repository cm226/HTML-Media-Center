/*
 * AbstractMessage.h
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#ifndef ABSTRACTMESSAGE_H_
#define ABSTRACTMESSAGE_H_

#include "../../../EventModel/EventModel.h"
#include "../StringMessageSerializer.h"
#include "../../../exportMacros.h"

class DLLCORE_API AbstractMessage {

protected:
	char* message;
	unsigned int length;
	unsigned int offset;
public:
	AbstractMessage(char* message, unsigned int length);
	AbstractMessage();
	virtual ~AbstractMessage();

	virtual AbstractMessage* actionMessage() = 0;
	std::string stripNextValue();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser) = 0;
};

#endif /* ABSTRACTMESSAGE_H_ */
