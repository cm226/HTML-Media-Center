/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_MESSAGETRANSLATERS_TRANSLATEDMESSAGES_REQUESTNEXTDATACHUNKMESSAGE_H
#define COREMODULES_COMMS_MESSAGETRANSLATERS_TRANSLATEDMESSAGES_REQUESTNEXTDATACHUNKMESSAGE_H

#include "../../../../../Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.h"

namespace TranslatedMessages {


/**
	RequestNextDataChunkMessage
*/
class RequestNextDataChunkMessage : public AbstractMessage
{
public:
	/**
		ctor
	*/
	RequestNextDataChunkMessage(char* data, unsigned int length);

	/**
		dtor
	*/
	~RequestNextDataChunkMessage();

	virtual AbstractMessage* actionMessage();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();

};



}


#endif



