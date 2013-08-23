/*
 * AgentRequestMessage.h
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#ifndef AGENTREQUESTMESSAGE_H_
#define AGENTREQUESTMESSAGE_H_

#include "AbstractMessage.h"

namespace TranslatedMessages {

class AgentRequestMessage: public AbstractMessage
{
public:
	AgentRequestMessage(char* message, unsigned int length);
	virtual ~AgentRequestMessage();

	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslatedMessages */
#endif /* AGENTREQUESTMESSAGE_H_ */
