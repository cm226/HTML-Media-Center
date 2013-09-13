/*
 * RequestDiagnosticMessageFilter.cpp
 *
 *  Created on: 12 Sep 2013
 *      Author: craig
 */

#include "RequestDiagnosticMessageFilter.h"

#include "../TranslatedMessages/RequestDisagnosticsMessage.h"

namespace TranslationFilters {

RequestDiagnosticMessageFilter::RequestDiagnosticMessageFilter(coremodules::comms::protocals::IProtocal* protocal)
	:TranslationFilters::BaseTranslationFilter(protocal)
{
	// TODO Auto-generated constructor stub

}

RequestDiagnosticMessageFilter::~RequestDiagnosticMessageFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* RequestDiagnosticMessageFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(TranslatedMessages::RequestDisagnosticsMessage::getHeader()) ==0 )
	{
		return new TranslatedMessages::RequestDisagnosticsMessage(bytes, bytesLength);
	}

	return forwardMessage(header, bytes, bytesLength);
}

}
