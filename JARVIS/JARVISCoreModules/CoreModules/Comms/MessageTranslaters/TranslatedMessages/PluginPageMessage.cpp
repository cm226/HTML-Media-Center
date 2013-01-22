/*
 * PlauginPageMessage.cpp
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#include "PluginPageMessage.h"

namespace TranslatedMessages {

PluginPageMessage::PluginPageMessage(const char* data, unsigned int length)
		:AbstractMessage(data,length)
{


}

PluginPageMessage::~PluginPageMessage() {

}

void PluginPageMessage::actionMessage(std::string* reply)
{
	this->stripNextValue(); // remove header from message
	std::string pluginName = this->stripNextValue();

	std::vector<std::string> replys;
	EventManager::onPluginViewRequest.notify(pluginName,&replys);

	*reply = replys[0];
}

} /* namespace TranslatedMessages */
