/*
 * AbstractMessage.h
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#ifndef ABSTRACTMESSAGE_H_
#define ABSTRACTMESSAGE_H_

#include "../../../EventModel/EventModel.h"

class AbstractMessage {

protected:
	const char* message;
	unsigned int length;
	unsigned int offset;
public:
	AbstractMessage(const char* message, unsigned int length);
	virtual ~AbstractMessage();

	virtual void actionMessage(std::string* reply) = 0;
	std::string stripNextValue();
};

#endif /* ABSTRACTMESSAGE_H_ */
