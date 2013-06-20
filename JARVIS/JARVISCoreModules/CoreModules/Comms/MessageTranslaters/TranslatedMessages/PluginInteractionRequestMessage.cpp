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

namespace TranslatedMessages {

PluginInteractionRequestMessage::PluginInteractionRequestMessage(char* data, unsigned int length):AbstractMessage(data,length) 
{
	
	this->stripNextValue(); // remove header from message
	callbackID = this->stripNextValue();
	pluginName = this->stripNextValue();

	if(callbackID.compare("") == 0 || pluginName.compare("") == 0)
		ErrorLogger::logError("Plugin interaction message error missing callbackID or plugin Name");

	//contextValues.push_back(callbackID);
	std::string nextConxtVal;
	while((nextConxtVal = this->stripNextValue()) != "")
		contextValues.push_back(nextConxtVal);
}

PluginInteractionRequestMessage::~PluginInteractionRequestMessage() {
	// TODO Auto-generated destructor stub
}


void PluginInteractionRequestMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}

std::string PluginInteractionRequestMessage::getHeader()
{
	return "pcb";
}

} /* namespace TranslationFilters */
