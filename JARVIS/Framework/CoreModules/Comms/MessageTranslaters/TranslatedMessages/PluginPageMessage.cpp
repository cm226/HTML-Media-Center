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
	//int value = atoi(comAndContValue.c_str());
	//if(value != 0)

	std::vector<std::string> replys;
	EventManager::onPluginViewRequest.notify(pluginName,&replys);

	reply = NULL;
}

} /* namespace TranslatedMessages */
