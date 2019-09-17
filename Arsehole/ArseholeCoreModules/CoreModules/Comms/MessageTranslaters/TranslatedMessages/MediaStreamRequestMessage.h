#pragma once
#include "../../../../../Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.h"
#include "../../../exportMacros.h"
#include <list>

namespace TranslatedMessages
{
class DLLCORE_API MediaStreamRequestMessage: public AbstractMessage 
{
	enum MEDIA_TYPE{AUDIO, VIDEO};
private:
	#pragma warning( disable : 4251)
	MEDIA_TYPE _media_type;
	std::list<int> _ids;
	#pragma warning( default : 4251)


public:
	MediaStreamRequestMessage(char* data, unsigned int length);
	virtual ~MediaStreamRequestMessage(void);

	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();

	std::list<int>& MediaIDs();
};
}

