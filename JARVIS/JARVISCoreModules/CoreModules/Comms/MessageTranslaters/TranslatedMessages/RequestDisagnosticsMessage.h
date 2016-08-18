/*
 * RequestDisagnosticsMessage.h
 *
 *  Created on: 12 Sep 2013
 *      Author: craig
 */
#ifndef REQUESTDISAGNOSTICSMESSAGE_H_
#define REQUESTDISAGNOSTICSMESSAGE_H_

#include "AbstractMessage.h"

namespace TranslatedMessages {

class DLLCORE_API RequestDisagnosticsMessage : public AbstractMessage
{
public:
	RequestDisagnosticsMessage(char* message, unsigned int length);
	virtual ~RequestDisagnosticsMessage();

	void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

}
#endif /* REQUESTDISAGNOSTICSMESSAGE_H_ */
