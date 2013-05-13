/*
	Author : Craig Matear
*/
#include "ReplyMessage.h"



namespace TranslatedMessages {

ReplyMessage::ReplyMessage(std::string content)
{
	this->content = content;
}



ReplyMessage::~ReplyMessage()
{
}


AbstractMessage* ReplyMessage::actionMessage()
{
	return NULL;
}

void ReplyMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{
	serialiser.serialiseValue(this->getHeader());
	serialiser.serialiseValue(this->content);
}

std::string ReplyMessage::getHeader()
{
	return "msgRpy";
}



}




