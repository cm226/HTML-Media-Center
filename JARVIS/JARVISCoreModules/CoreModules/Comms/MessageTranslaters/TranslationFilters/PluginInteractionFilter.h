/*
 * PluginPollTranslationFilter.h
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#ifndef PLUGININTERACTIONFILTER_H_
#define PLUGININTERACTIONFILTER_H_

#include "BaseTranslationFilter.h"

namespace TranslationFilters {

class PluginInteractionFilter: public TranslationFilters::BaseTranslationFilter {
public:
	PluginInteractionFilter();
	virtual ~PluginInteractionFilter();

	virtual AbstractMessage* translateMessage(std::string header,const  char* bytes, unsigned int bytesLength);
};

} /* namespace TranslationFilters */
#endif
