/*
 * CommandAndcontrolTranslationFilter.h
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#ifndef COMMANDANDCONTROLTRANSLATIONFILTER_H_
#define COMMANDANDCONTROLTRANSLATIONFILTER_H_

#include "BaseTranslationFilter.h"
#include "../../Protocals/IProtocal.h"

namespace TranslationFilters {

class CommandAndcontrolTranslationFilter: public TranslationFilters::BaseTranslationFilter {
public:
	CommandAndcontrolTranslationFilter(coremodules::comms::protocals::IProtocal* protocal);
	virtual ~CommandAndcontrolTranslationFilter();

	virtual AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength);
};

} /* namespace TranslationFilters */
#endif /* COMMANDANDCONTROLTRANSLATIONFILTER_H_ */
