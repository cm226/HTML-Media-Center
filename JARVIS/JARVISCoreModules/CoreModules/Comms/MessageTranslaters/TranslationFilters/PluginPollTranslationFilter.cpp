/*
 * PluginPollTranslationFilter.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#include "PluginPollTranslationFilter.h"

namespace TranslationFilters {

PluginPollTranslationFilter::PluginPollTranslationFilter() {

}

PluginPollTranslationFilter::~PluginPollTranslationFilter() {
}

AbstractMessage* PluginPollTranslationFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(ListPluginsMessage::getHeader()) == 0)
	{
		return new ListPluginsMessage(bytes, bytesLength);
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
