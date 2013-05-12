/*
 * ComandAndControlMessage.cpp
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#include "PluginInteractionRequestMessage.h"
#include "../../../Errors/ErrorLogger.h"
#include "ReplyMessage.h"
#include <stdlib.h>
#include <vector>

namespace TranslationFilters {

PluginInteractionRequestMessage::PluginInteractionRequestMessage(char* data, unsigned int length):AbstractMessage(data,length) {
	// TODO Auto-generated constructor stub

}

PluginInteractionRequestMessage::~PluginInteractionRequestMessage() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* PluginInteractionRequestMessage::actionMessage()
{
	this->stripNextValue(); // remove header from message

	std::string callbackID = this->stripNextValue();
	std::vector<std::string> contextValues;
	contextValues.push_back(callbackID);
	std::string nextConxtVal;
	while((nextConxtVal = this->stripNextValue()) != "")
		contextValues.push_back(nextConxtVal);

	std::vector<std::string> returnVals;
	EventManager::onPluginInteractionRequest.notify(contextValues, &returnVals);

	if(returnVals.size() != 1)
	{
		ErrorLogger::logError("ambiguity in returns from plugin interaction more than 1 subscriber to same plugin");
	}
	return new TranslatedMessages::ReplyMessage(returnVals[0]);
}

void PluginInteractionRequestMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}

std::string PluginInteractionRequestMessage::getHeader()
{
	return "pcb";
}

} /* namespace TranslationFilters */
