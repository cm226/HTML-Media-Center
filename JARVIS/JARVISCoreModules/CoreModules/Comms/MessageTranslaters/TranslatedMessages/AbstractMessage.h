/*
 * AbstractMessage.h
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */
#pragma once
#ifndef ABSTRACTMESSAGE_H_
#define ABSTRACTMESSAGE_H_

#include "../../Protocals/StringMessageSerializer.h"
#include "../../../exportMacros.h"

class DLLCORE_API AbstractMessage
{

protected:
	char* message;
	unsigned int length;
	unsigned int offset;
public:
	AbstractMessage(char* message, unsigned int length);
	AbstractMessage();
	virtual ~AbstractMessage();

	std::string stripNextValue();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser) = 0;
};

#endif /* ABSTRACTMESSAGE_H_ */
