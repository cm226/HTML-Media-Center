/*
 * ComandAndControlMessage.cpp
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#include "PluginInteractionRequestMessage.h"
#include "../../../Errors/ErrorLogger.h"
#include <stdlib.h>
#include <vector>

namespace TranslationFilters {

PluginInteractionRequestMessage::PluginInteractionRequestMessage(const char* data, unsigned int length):AbstractMessage(data,length) {
	// TODO Auto-generated constructor stub

}

PluginInteractionRequestMessage::~PluginInteractionRequestMessage() {
	// TODO Auto-generated destructor stub
}

void PluginInteractionRequestMessage::actionMessage(std::string* reply)
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
	*reply = returnVals[0];
}

} /* namespace TranslationFilters */
