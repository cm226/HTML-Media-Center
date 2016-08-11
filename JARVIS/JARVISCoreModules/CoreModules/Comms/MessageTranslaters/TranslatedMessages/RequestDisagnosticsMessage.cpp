/*
 * RequestDisagnosticsMessage.cpp
 *
 *  Created on: 12 Sep 2013
 *      Author: craig
 */

#include "RequestDisagnosticsMessage.h"

namespace TranslatedMessages {

RequestDisagnosticsMessage::RequestDisagnosticsMessage(char* message, unsigned int length)
 :AbstractMessage(message, length)
{

}

RequestDisagnosticsMessage::~RequestDisagnosticsMessage()
{

}

void RequestDisagnosticsMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}

std::string RequestDisagnosticsMessage::getHeader()
{
	return "RDiag";
}

}
