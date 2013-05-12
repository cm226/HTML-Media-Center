/*
 * PluginPollTranslationFilter.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#include "PluginInteractionFilter.h"
#include "../TranslatedMessages/PluginInteractionRequestMessage.h"

namespace TranslationFilters {

PluginInteractionFilter::PluginInteractionFilter() {

}

PluginInteractionFilter::~PluginInteractionFilter() {
}

AbstractMessage* PluginInteractionFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(PluginInteractionRequestMessage::getHeader()) == 0)
	{
		return new PluginInteractionRequestMessage(bytes, bytesLength);
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
