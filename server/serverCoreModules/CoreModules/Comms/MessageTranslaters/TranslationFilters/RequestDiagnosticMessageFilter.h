/*
 * RequestDiagnosticMessageFilter.h
 *
 *  Created on: 12 Sep 2013
 *      Author: craig
 */

#ifndef REQUESTDIAGNOSTICMESSAGEFILTER_H_
#define REQUESTDIAGNOSTICMESSAGEFILTER_H_

#include "BaseTranslationFilter.h"

namespace TranslationFilters {

class RequestDiagnosticMessageFilter : public BaseTranslationFilter
{
public:
	RequestDiagnosticMessageFilter(coremodules::comms::protocals::IProtocal* protocal);
	virtual ~RequestDiagnosticMessageFilter();

	AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength);
};
}

#endif /* REQUESTDIAGNOSTICMESSAGEFILTER_H_ */
