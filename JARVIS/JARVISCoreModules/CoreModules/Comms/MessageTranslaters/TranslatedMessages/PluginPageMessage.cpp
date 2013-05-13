/*
 * PlauginPageMessage.cpp
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#include "PluginPageMessage.h"
#include "ReplyMessage.h"

namespace TranslatedMessages {

PluginPageMessage::PluginPageMessage(char* data, unsigned int length)
		:AbstractMessage(data,length)
{


}

PluginPageMessage::~PluginPageMessage() {

}

AbstractMessage* PluginPageMessage::actionMessage()
{
	this->stripNextValue(); // remove header from message
	std::string pluginName = this->stripNextValue();

	std::vector<std::string> replys;
	EventManager::onPluginViewRequest.notify(pluginName,&replys);

	return new TranslatedMessages::ReplyMessage(replys[0]);
}

void PluginPageMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}

std::string PluginPageMessage::getHeader()
{
	return "rpp";
}

} /* namespace TranslatedMessages */
