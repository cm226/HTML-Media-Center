/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_MESSAGETRANSLATERS_TRANSLATEDMESSAGES_PLUGINPAGEREPLYMESSAGE_H
#define COREMODULES_COMMS_MESSAGETRANSLATERS_TRANSLATEDMESSAGES_PLUGINPAGEREPLYMESSAGE_H
#include "AbstractMessage.h"

namespace TranslatedMessages {

/**
	PluginPageReplyMessage
*/
class ReplyMessage : public AbstractMessage
{
private:
	std::string content;
public:
	/**
		ctor
	*/
	ReplyMessage(std::string content);

	/**
		dtor
	*/
	~ReplyMessage();

	virtual AbstractMessage* actionMessage();
	virtual void serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser);
	static std::string getHeader();

};




}


#endif



