/*
 * ComandAndControlMessage.cpp
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#include "ComandAndControlMessage.h"
#include <stdlib.h>

namespace TranslationFilters {

ComandAndControlMessage::ComandAndControlMessage(const char* data, unsigned int length):AbstractMessage(data,length) {
	// TODO Auto-generated constructor stub

}

ComandAndControlMessage::~ComandAndControlMessage() {
	// TODO Auto-generated destructor stub
}

void ComandAndControlMessage::actionMessage(std::string* reply)
{
	this->stripNextValue(); // remove header from message
	std::string comAndContValue = this->stripNextValue();
	int value = atoi(comAndContValue.c_str());
	if(value != 0)
		EventManager::commandAndControlMessageReceved.notify(value, NULL);

	reply = NULL;
}

} /* namespace TranslationFilters */
