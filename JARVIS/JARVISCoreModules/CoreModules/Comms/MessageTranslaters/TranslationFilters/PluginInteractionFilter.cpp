/*
 * PluginPollTranslationFilter.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#include "PluginInteractionFilter.h"
#include "../TranslatedMessages/PluginInteractionRequestMessage.h"
#include "../../Comms.h"
#include "../../../../../ErrorLogger/Errors/ErrorLogger.h"

namespace TranslationFilters {

PluginInteractionFilter::PluginInteractionFilter(coremodules::comms::protocals::IProtocal* protocal) : BaseTranslationFilter(protocal){

}

PluginInteractionFilter::~PluginInteractionFilter() {
}

AbstractMessage* PluginInteractionFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(TranslatedMessages::PluginInteractionRequestMessage::getHeader()) == 0)
	{
		ErrorLogger::logInfo("Plugin Interaction Message Receved");
		TranslatedMessages::PluginInteractionRequestMessage* msg = new TranslatedMessages::PluginInteractionRequestMessage(bytes, bytesLength);
		Comms::_messageSubject.onPluginInteractionMessageReceved.signal(msg,protocal);

		return msg;
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
