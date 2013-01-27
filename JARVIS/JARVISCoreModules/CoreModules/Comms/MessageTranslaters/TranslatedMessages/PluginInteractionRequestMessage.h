/*
 * ComandAndControlMessage.h
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#ifndef PLUGININTERACTIONREQUESTMESSAGE_H_
#define PLUGININTERACTIONREQUESTMESSAGE_H_

#include "AbstractMessage.h"

namespace TranslationFilters {

class PluginInteractionRequestMessage: public AbstractMessage {
public:
	PluginInteractionRequestMessage(const char* data, unsigned int length);
	virtual ~PluginInteractionRequestMessage();

	virtual void actionMessage(std::string* reply);
};

} /* namespace TranslationFilters */
#endif /* COMANDANDCONTROLMESSAGE_H_ */
