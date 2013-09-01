/*
 * AbstractMessage.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#include "AbstractMessage.h"

AbstractMessage::AbstractMessage(char* data, unsigned int length)
{
	this->message = data;
	this->length = length;
	this->offset = 0;
}

AbstractMessage::AbstractMessage()
{
	this->message = NULL;
}

AbstractMessage::~AbstractMessage()
{
	if(this->message)
		delete[] this->message;
}

std::string AbstractMessage::stripNextValue()
{
	char curChar = this->message[this->offset];
	std::string nextValue = "";

	this->offset++;
	while(curChar != '$' && this->offset <= this->length)
	{
		nextValue.append(&curChar,1);
		curChar = this->message[this->offset];
		this->offset++;
	}
	//this->offset++; // move index past current $
	return nextValue;
}
