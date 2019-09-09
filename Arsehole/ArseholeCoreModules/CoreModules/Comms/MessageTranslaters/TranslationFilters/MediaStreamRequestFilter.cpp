#include "MediaStreamRequestFilter.h"
#include "../../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../TranslatedMessages/MediaStreamRequestMessage.h"
#include "../../Comms.h"

namespace TranslationFilters
{

MediaStreamRequestFilter::MediaStreamRequestFilter(coremodules::comms::protocals::IProtocal* protocal) : BaseTranslationFilter(protocal)
{

}


MediaStreamRequestFilter::~MediaStreamRequestFilter(void)
{

}

AbstractMessage* MediaStreamRequestFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(TranslatedMessages::MediaStreamRequestMessage::getHeader()) == 0)
		{
			ErrorLogger::logInfo("Media Stream Request Message Receved");
			TranslatedMessages::MediaStreamRequestMessage* msg = new TranslatedMessages::MediaStreamRequestMessage(bytes, bytesLength);
			Comms::_messageSubject.onMediaStreamRequestMessageReceved.signal(msg,protocal);
			return msg;
		}

		return this->forwardMessage(header,bytes,bytesLength);
}

}
