/*
 * PlauginPageMessage.h
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#ifndef PLAUGINPAGEMESSAGE_H_
#define PLAUGINPAGEMESSAGE_H_

#include "AbstractMessage.h"

namespace TranslatedMessages {

class PluginPageMessage: public AbstractMessage {
public:
	PluginPageMessage(char* data, unsigned int length);
	virtual ~PluginPageMessage();

	virtual AbstractMessage* actionMessage();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslatedMessages */
#endif /* PLAUGINPAGEMESSAGE_H_ */
