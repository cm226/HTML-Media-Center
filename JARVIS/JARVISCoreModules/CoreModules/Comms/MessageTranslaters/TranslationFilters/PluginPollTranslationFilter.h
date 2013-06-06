/*
 * PluginPollTranslationFilter.h
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#ifndef PLUGINPOLLTRANSLATIONFILTER_H_
#define PLUGINPOLLTRANSLATIONFILTER_H_

#include "BaseTranslationFilter.h"
#include "../../Protocals/IProtocal.h"

namespace TranslationFilters {

class PluginPollTranslationFilter: public TranslationFilters::BaseTranslationFilter {
public:
	PluginPollTranslationFilter(coremodules::comms::protocals::IProtocal* protocal);
	virtual ~PluginPollTranslationFilter();

	virtual AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength);
};

} /* namespace TranslationFilters */
#endif /* PLUGINPOLLTRANSLATIONFILTER_H_ */
