/*
 * AgentRequestMessage.h
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#ifndef AGENTREQUESTMESSAGE_H_
#define AGENTREQUESTMESSAGE_H_

#include "AbstractMessage.h"
#include "../../../exportMacros.h"
>>>>>>> f4855cc0357f94ea74b95d110b8d2209c43a1b07

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
