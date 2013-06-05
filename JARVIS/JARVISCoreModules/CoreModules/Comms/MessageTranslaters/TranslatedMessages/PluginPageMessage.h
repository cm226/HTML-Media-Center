/*
 * PlauginPageMessage.h
 *
 *  Created on: 14 Nov 2012
 *      Author: craig
 */

#ifndef PLAUGINPAGEMESSAGE_H_
#define PLAUGINPAGEMESSAGE_H_

#include "AbstractMessage.h"
#include "../../../exportMacros.h"
#include <string>

namespace TranslatedMessages {

class DLLCORE_API PluginPageMessage: public AbstractMessage
{
private:
	#pragma warning( disable : 4251)
	std::string _pluginName;
	#pragma warning( default : 4251)

public:
	const char* pluginName();

	PluginPageMessage(char* data, unsigned int length);
	virtual ~PluginPageMessage();

	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};

} /* namespace TranslatedMessages */
#endif /* PLAUGINPAGEMESSAGE_H_ */
