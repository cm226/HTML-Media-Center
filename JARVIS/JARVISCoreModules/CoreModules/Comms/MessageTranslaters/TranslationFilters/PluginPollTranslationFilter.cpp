/*
 * PluginPollTranslationFilter.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#include "PluginPollTranslationFilter.h"
#include "../../Comms.h"
#include "../../../../../ErrorLogger/Errors/ErrorLogger.h"

namespace TranslationFilters {

PluginPollTranslationFilter::PluginPollTranslationFilter(coremodules::comms::protocals::IProtocal* protocal) : BaseTranslationFilter(protocal)
{

}

PluginPollTranslationFilter::~PluginPollTranslationFilter() {
}

AbstractMessage* PluginPollTranslationFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(ListPluginsMessage::getHeader()) == 0)
	{
		ErrorLogger::logInfo("Plugin Poll Message Receved");
		ListPluginsMessage* msg = new ListPluginsMessage(bytes, bytesLength);
		Comms::_messageSubject.onListPluginsMessageReceved.signal(msg,protocal);
		return msg;
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
