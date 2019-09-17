/*
 * BaseTranslationFilter.h
 *
 *  Created on: Oct 11, 2012
 *      Author: craig
 */

#ifndef BASETRANSLATIONFILTER_H_
#define BASETRANSLATIONFILTER_H_

#include <string>
#include "../TranslatedMessages/TranslatedMessages.h"
#include "../../../../../Comms/Protocals/IProtocal.h"

namespace TranslationFilters {

class BaseTranslationFilter {

	BaseTranslationFilter* nextFilter;
protected:
	coremodules::comms::protocals::IProtocal* protocal;

public:
	BaseTranslationFilter(coremodules::comms::protocals::IProtocal* protocal);
	virtual ~BaseTranslationFilter();
	void setNextFilter(BaseTranslationFilter* filter);
	AbstractMessage* forwardMessage(std::string header, char* bytes, unsigned int bytesLength);

	virtual AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength) = 0;
};

} /* namespace TranslationFilters */
#endif /* BASETRANSLATIONFILTER_H_ */
