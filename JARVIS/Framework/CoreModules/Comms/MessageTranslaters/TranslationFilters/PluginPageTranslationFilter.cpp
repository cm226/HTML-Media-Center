/*
 * PluginPageTranslationFilter.cpp
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#include "PluginPageTranslationFilter.h"

namespace TranslationFilters {

PluginPageTranslationFilter::PluginPageTranslationFilter() {
	// TODO Auto-generated constructor stub

}

PluginPageTranslationFilter::~PluginPageTranslationFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* PluginPageTranslationFilter::translateMessage(std::string header, const char* bytes, unsigned int bytesLength)
{
	if(header.compare("rpp") == 0)
	{
		return new TranslatedMessages::PluginPageMessage(bytes, bytesLength);
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
