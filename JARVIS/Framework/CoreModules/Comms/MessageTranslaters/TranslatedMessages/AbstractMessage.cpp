/*
 * AbstractMessage.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#include "AbstractMessage.h"

AbstractMessage::AbstractMessage(const char* data, unsigned int length)
{
	this->message = data;
	this->length = length;
}

AbstractMessage::~AbstractMessage() {
	// TODO Auto-generated destructor stub
}

