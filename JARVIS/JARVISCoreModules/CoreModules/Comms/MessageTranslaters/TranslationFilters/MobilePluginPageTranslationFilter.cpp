/*
 * MobilePluginPageTranslationFilter.cpp
 *
 *  Created on: 25 Jul 2013
 *      Author: craig
 */

#include "MobilePluginPageTranslationFilter.h"
#include "../TranslatedMessages/MobilePluginPageMessage.h"

namespace TranslationFilters {

MobilePluginPageTranslationFilter::MobilePluginPageTranslationFilter(coremodules::comms::protocals::IProtocal* protocal)
:BaseTranslationFilter(protocal)
	{
	// TODO Auto-generated constructor stub

}

MobilePluginPageTranslationFilter::~MobilePluginPageTranslationFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* MobilePluginPageTranslationFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(TranslatedMessages::MobilePluginPageMessage::getHeader()) == 0)
		{
			ErrorLogger::logInfo("Mobile Plugin Page Message Receved");
			TranslatedMessages::MobilePluginPageMessage* msg = new TranslatedMessages::MobilePluginPageMessage(bytes, bytesLength);
			Comms::_messageSubject.onMobilePluginPageMessageReceved.signal(msg,protocal);
			return msg;
		}

		return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
