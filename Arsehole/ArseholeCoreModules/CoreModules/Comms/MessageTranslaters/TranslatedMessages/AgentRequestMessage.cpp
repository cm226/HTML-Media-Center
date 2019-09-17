/*
 * AgentRequestMessage.cpp
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#include "AgentRequestMessage.h"

namespace TranslatedMessages {

AgentRequestMessage::AgentRequestMessage(char* message, unsigned int length)
	:AbstractMessage(message, length)
{
	// TODO Auto-generated constructor stub

}

AgentRequestMessage::~AgentRequestMessage() {
	// TODO Auto-generated destructor stub
}

void AgentRequestMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}

std::string AgentRequestMessage::getHeader()
{
	return "APR";
}



} /* namespace TranslatedMessages */
