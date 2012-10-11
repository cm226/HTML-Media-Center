/*
 * PluginPollTranslationFilter.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#include "PluginPollTranslationFilter.h"

namespace TranslationFilters {

PluginPollTranslationFilter::PluginPollTranslationFilter() {
	// TODO Auto-generated constructor stub

}

PluginPollTranslationFilter::~PluginPollTranslationFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* PluginPollTranslationFilter::translateMessage(std::string header, const char* bytes, unsigned int bytesLength)
{
	if(header.compare("ppoll") == 0)
	{
		return new ListPluginsMessage(bytes, bytesLength);
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
