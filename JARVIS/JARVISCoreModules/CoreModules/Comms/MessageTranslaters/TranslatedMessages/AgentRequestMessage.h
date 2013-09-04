/*
 * AgentRequestMessage.h
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#ifndef AGENTREQUESTMESSAGE_H_
#define AGENTREQUESTMESSAGE_H_

#include "../../../../../Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.h"
#include "../../../exportMacros.h"

namespace TranslatedMessages {

class DLLCORE_API AgentRequestMessage: public AbstractMessage
{
public:
	AgentRequestMessage(char* message, unsigned int length);
	virtual ~AgentRequestMessage();

	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslatedMessages */
#endif /* AGENTREQUESTMESSAGE_H_ */
