/*
 * PlauginPageMessage.cpp
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#include "PluginPageMessage.h"

namespace TranslatedMessages {

PluginPageMessage::PluginPageMessage(char* data, unsigned int length)
		:AbstractMessage(data,length)
{
	this->stripNextValue(); // remove header from message
	this->_pluginName = this->stripNextValue();

}

PluginPageMessage::~PluginPageMessage() {

}

void PluginPageMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}

const char* PluginPageMessage::pluginName()
{
	return this->_pluginName.c_str();
}

std::string PluginPageMessage::getHeader()
{
	return "rpp";
}

} /* namespace TranslatedMessages */
