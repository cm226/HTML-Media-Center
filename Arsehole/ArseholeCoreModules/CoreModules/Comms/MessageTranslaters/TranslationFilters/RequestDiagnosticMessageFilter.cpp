/*
 * RequestDiagnosticMessageFilter.cpp
 *
 *  Created on: 12 Sep 2013
 *      Author: craig
 */

#include "RequestDiagnosticMessageFilter.h"

#include "../TranslatedMessages/RequestDisagnosticsMessage.h"
#include "../../Comms.h"
#include "../../../../../ErrorLogger/Errors/ErrorLogger.h"

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
		ErrorLogger::logInfo("Plugin Page Message Receved");
		TranslatedMessages::RequestDisagnosticsMessage* msg = new TranslatedMessages::RequestDisagnosticsMessage(bytes, bytesLength);
		Comms::_messageSubject.onDiagnosticMessageReceved.signal(msg,protocal);
		return msg;
	}

	return forwardMessage(header, bytes, bytesLength);
}

}
