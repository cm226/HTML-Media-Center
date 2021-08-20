/*
 * MobilePluginPageMessage.cpp
 *
 *  Created on: 24 Jul 2013
 *      Author: craig
 */

#include "MobilePluginPageMessage.h"

namespace TranslatedMessages {

MobilePluginPageMessage::MobilePluginPageMessage(char* data, unsigned int length)
:AbstractMessage(data,length)
{
	this->stripNextValue(); // remove header from message
	this->_pluginName = this->stripNextValue();
}

MobilePluginPageMessage::~MobilePluginPageMessage() {
	// TODO Auto-generated destructor stub
}

const char* MobilePluginPageMessage::pluginName()
{
	return this->_pluginName.c_str();
}

void MobilePluginPageMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}
std::string MobilePluginPageMessage::getHeader()
{
	return "rmpp";
}

} /* namespace TranslatedMessages */
