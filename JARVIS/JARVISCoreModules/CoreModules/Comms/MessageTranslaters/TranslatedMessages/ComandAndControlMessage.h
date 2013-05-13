/*
 * ComandAndControlMessage.h
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#ifndef COMANDANDCONTROLMESSAGE_H_
#define COMANDANDCONTROLMESSAGE_H_

#include "AbstractMessage.h"

namespace TranslationFilters {

class ComandAndControlMessage: public AbstractMessage {
public:
	ComandAndControlMessage(char* data, unsigned int length);
	virtual ~ComandAndControlMessage();

	virtual AbstractMessage* actionMessage();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslationFilters */
#endif /* COMANDANDCONTROLMESSAGE_H_ */
