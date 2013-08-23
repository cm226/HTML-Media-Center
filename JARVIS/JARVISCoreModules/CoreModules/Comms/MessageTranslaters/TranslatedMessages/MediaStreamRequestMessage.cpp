#include "MediaStreamRequestMessage.h"
#include "../../../../../ErrorLogger/Errors/ErrorLogger.h"
#include <boost/lexical_cast.hpp>

namespace TranslatedMessages
{
MediaStreamRequestMessage::MediaStreamRequestMessage(char* data, unsigned int length): AbstractMessage(data, length)
{
	this->stripNextValue(); // remove header
	
	while(offset < length)
	{
		std::string nextValue = this->stripNextValue();
		try
		{
			int id = boost::lexical_cast<int>(nextValue);
			_ids.push_back(id);
		}
		catch(boost::bad_lexical_cast &)
        {
			ErrorLogger::logError("Media Stream Request message contained bad media ID:" + nextValue);
        }
	}


}


MediaStreamRequestMessage::~MediaStreamRequestMessage(void)
{

}

void MediaStreamRequestMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{
	ErrorLogger::logError("Serialising Media stream message not implemented");
}

std::string MediaStreamRequestMessage::getHeader()
{
	return "RMS";
}

std::list<int>& MediaStreamRequestMessage::MediaIDs()
{
	return _ids;
}


}
