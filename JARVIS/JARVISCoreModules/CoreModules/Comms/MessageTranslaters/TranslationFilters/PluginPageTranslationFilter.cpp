/*
 * PluginPageTranslationFilter.cpp
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#include "PluginPageTranslationFilter.h"
#include "../../Comms.h"

namespace TranslationFilters {

PluginPageTranslationFilter::PluginPageTranslationFilter(coremodules::comms::protocals::IProtocal* protocal): BaseTranslationFilter(protocal) {
	// TODO Auto-generated constructor stub

}

PluginPageTranslationFilter::~PluginPageTranslationFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* PluginPageTranslationFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(TranslatedMessages::PluginPageMessage::getHeader()) == 0)
	{
		TranslatedMessages::PluginPageMessage* msg = new TranslatedMessages::PluginPageMessage(bytes, bytesLength);
		Comms::_messageSubject.onPluginPageMessageReceved.signal(msg,protocal);
		return msg;
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
