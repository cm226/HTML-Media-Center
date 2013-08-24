/*
 * AgentPollRequestFilter.cpp
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#include "AgentPollRequestFilter.h"
#include "../TranslatedMessages/AgentRequestMessage.h"
#include "../../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../Comms.h"

namespace TranslationFilters {

AgentPollRequestFilter::AgentPollRequestFilter(coremodules::comms::protocals::IProtocal* protocal)
	:BaseTranslationFilter(protocal)
{
	// TODO Auto-generated constructor stub

}

AgentPollRequestFilter::~AgentPollRequestFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* AgentPollRequestFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(TranslatedMessages::AgentRequestMessage::getHeader()) == 0)
	{
		ErrorLogger::logInfo("Agent Poll Request Message Receved");
		TranslatedMessages::AgentRequestMessage* msg = new TranslatedMessages::AgentRequestMessage(bytes, bytesLength);
		Comms::_messageSubject.onAgentRequestMessageReceved.signal(msg,protocal);
		return msg;
	}

	return this->forwardMessage(header,bytes,bytesLength);
}

} /* namespace TranslationFilters */
