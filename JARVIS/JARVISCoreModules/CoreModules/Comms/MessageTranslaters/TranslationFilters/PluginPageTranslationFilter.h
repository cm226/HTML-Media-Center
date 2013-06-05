/*
 * PluginPageTranslationFilter.h
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#ifndef PLUGINPAGETRANSLATIONFILTER_H_
#define PLUGINPAGETRANSLATIONFILTER_H_

#include "BaseTranslationFilter.h"
#include "../../Protocals/IProtocal.h"

namespace TranslationFilters {

class PluginPageTranslationFilter: public TranslationFilters::BaseTranslationFilter {
public:
	PluginPageTranslationFilter(coremodules::comms::protocals::IProtocal* protocal);
	virtual ~PluginPageTranslationFilter();

	virtual AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength);
};

} /* namespace TranslationFilters */
#endif /* PLUGINPAGETRANSLATIONFILTER_H_ */
