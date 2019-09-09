/*
 * ComandAndControlMessage.h
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#ifndef PLUGININTERACTIONREQUESTMESSAGE_H_
#define PLUGININTERACTIONREQUESTMESSAGE_H_

#include "../../../../../Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.h"
#include "../../../exportMacros.h"
#include <string>
#include <list>

namespace TranslatedMessages {

class DLLCORE_API PluginInteractionRequestMessage: public AbstractMessage 
{
public:

	#pragma warning( disable : 4251)
	std::string callbackID;
	std::string pluginName;
	std::list<std::string> contextValues;
	#pragma warning( default : 4251)

	PluginInteractionRequestMessage(char* data, unsigned int length);
	virtual ~PluginInteractionRequestMessage();

	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslationFilters */
#endif /* COMANDANDCONTROLMESSAGE_H_ */
