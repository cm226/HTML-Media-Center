/*
 * ComandAndControlMessage.cpp
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#include "ComandAndControlMessage.h"
#include <stdlib.h>

namespace TranslationFilters {

ComandAndControlMessage::ComandAndControlMessage(char* data, unsigned int length):AbstractMessage(data,length) {
	// TODO Auto-generated constructor stub

}

ComandAndControlMessage::~ComandAndControlMessage() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* ComandAndControlMessage::actionMessage()
{
	this->stripNextValue(); // remove header from message
	std::string comAndContValue = this->stripNextValue();
	int value = atoi(comAndContValue.c_str());
	if(value != 0)
		//EventManager::commandAndControlMessageReceved.notify(value, NULL);

	 return NULL;
}

void ComandAndControlMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}
std::string ComandAndControlMessage::getHeader()
{
	return "c&c";
}


} /* namespace TranslationFilters */
