/*
 * BaseTranslationFilter.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#include "BaseTranslationFilter.h"

namespace TranslationFilters {

BaseTranslationFilter::BaseTranslationFilter(coremodules::comms::protocals::IProtocal* protocal) : protocal(protocal)
{
	this->nextFilter = NULL;

}

BaseTranslationFilter::~BaseTranslationFilter() {
	if(this->nextFilter != NULL)
		delete this->nextFilter;
}

AbstractMessage* BaseTranslationFilter::forwardMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(this->nextFilter != NULL)
		return this->nextFilter->translateMessage(header,bytes,bytesLength);

	return NULL;
}

void BaseTranslationFilter::setNextFilter(BaseTranslationFilter* filter)
{
	this->nextFilter = filter;
}

} /* namespace TranslationFilters */
