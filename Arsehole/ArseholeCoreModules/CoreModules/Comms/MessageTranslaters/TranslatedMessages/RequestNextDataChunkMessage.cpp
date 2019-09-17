/*
	Author : Craig Matear
*/
#include "RequestNextDataChunkMessage.h"



namespace TranslatedMessages {



RequestNextDataChunkMessage::RequestNextDataChunkMessage(char* data, unsigned int length) :AbstractMessage(data,length)
{
}



RequestNextDataChunkMessage::~RequestNextDataChunkMessage()
{
}


AbstractMessage* RequestNextDataChunkMessage::actionMessage()
{
	return NULL;
}

void RequestNextDataChunkMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{

}

std::string RequestNextDataChunkMessage::getHeader()
{
	return "RNDC";
}

}

