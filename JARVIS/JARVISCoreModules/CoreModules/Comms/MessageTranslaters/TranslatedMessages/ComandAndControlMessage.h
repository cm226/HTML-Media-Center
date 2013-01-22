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
	ComandAndControlMessage(const char* data, unsigned int length);
	virtual ~ComandAndControlMessage();

	virtual void actionMessage(std::string* reply);
};

} /* namespace TranslationFilters */
#endif /* COMANDANDCONTROLMESSAGE_H_ */
