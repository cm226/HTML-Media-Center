/*
 * MobilePluginPageTranslationFilter.h
 *
 *  Created on: 25 Jul 2013
 *      Author: craig
 */

#ifndef MOBILEPLUGINPAGETRANSLATIONFILTER_H_
#define MOBILEPLUGINPAGETRANSLATIONFILTER_H_

#include "BaseTranslationFilter.h"
#include "../../Protocals/IProtocal.h"

namespace TranslationFilters {

class MobilePluginPageTranslationFilter: public TranslationFilters::BaseTranslationFilter {
public:
	MobilePluginPageTranslationFilter(coremodules::comms::protocals::IProtocal* protocal);
	virtual ~MobilePluginPageTranslationFilter();

	virtual AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength);
};

} /* namespace TranslationFilters */
#endif /* MOBILEPLUGINPAGETRANSLATIONFILTER_H_ */
