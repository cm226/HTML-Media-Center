#pragma once
#include "AbstractMessage.h"
#include "../../../exportMacros.h"
#include <list>

namespace TranslatedMessages
{
class DLLCORE_API MediaStreamRequestMessage: public AbstractMessage 
{
	enum MEDIA_TYPE{AUDIO, VIDEO};
private:
	MEDIA_TYPE _media_type;
	std::list<int> ids;


public:
	MediaStreamRequestMessage(char* data, unsigned int length);
	virtual ~MediaStreamRequestMessage(void);

	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();
};
}

