/*
 * MobilePluginPageMessage.h
 *
 *  Created on: 24 Jul 2013
 *      Author: craig
 */

#ifndef MOBILEPLUGINPAGEMESSAGE_H_
#define MOBILEPLUGINPAGEMESSAGE_H_

#include "../../../../../Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.h"
#include "../../../exportMacros.h"

namespace TranslatedMessages {

class DLLCORE_API MobilePluginPageMessage: public AbstractMessage {
private:
	#pragma warning( disable : 4251)
	std::string _pluginName;
	#pragma warning( default : 4251)

public:
	const char* pluginName();

	MobilePluginPageMessage(char* data, unsigned int length);
	virtual ~MobilePluginPageMessage();

	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslatedMessages */
#endif /* MOBILEPLUGINPAGEMESSAGE_H_ */
