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
	PluginPageMessage(const char* data, unsigned int length);
	virtual ~PluginPageMessage();

	virtual void actionMessage(std::string* reply);
};

} /* namespace TranslatedMessages */
#endif /* PLAUGINPAGEMESSAGE_H_ */
