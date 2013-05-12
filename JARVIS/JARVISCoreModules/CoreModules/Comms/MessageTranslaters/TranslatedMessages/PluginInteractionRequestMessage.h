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
	PluginInteractionRequestMessage(char* data, unsigned int length);
	virtual ~PluginInteractionRequestMessage();

	virtual AbstractMessage* actionMessage();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslationFilters */
#endif /* COMANDANDCONTROLMESSAGE_H_ */
