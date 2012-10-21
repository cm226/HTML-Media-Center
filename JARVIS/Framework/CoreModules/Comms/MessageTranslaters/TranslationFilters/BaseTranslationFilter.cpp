/*
 * BaseTranslationFilter.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#include "BaseTranslationFilter.h"

namespace TranslationFilters {

BaseTranslationFilter::BaseTranslationFilter() {
	this->nextFilter = NULL;

}

BaseTranslationFilter::~BaseTranslationFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* BaseTranslationFilter::forwardMessage(std::string header, const char* bytes, unsigned int bytesLength)
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
