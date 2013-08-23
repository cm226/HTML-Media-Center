/*
 * AgentRequestReplyMessage.h
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#ifndef AGENTREQUESTREPLYMESSAGE_H_
#define AGENTREQUESTREPLYMESSAGE_H_

#include "AbstractMessage.h"
#include <list>
#include <string>

namespace TranslatedMessages {

class AgentRequestReplyMessage: public AbstractMessage
{
private:
	std::list<std::string> _agents;

public:
	AgentRequestReplyMessage();
	virtual ~AgentRequestReplyMessage();

	void Add_Agent(std::string agent);
	void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);

	static std::string getHeader();
};

} /* namespace TranslatedMessages */
#endif /* AGENTREQUESTREPLYMESSAGE_H_ */
