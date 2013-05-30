/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_MESSAGETRANSLATERS_TRANSLATEDMESSAGES_PLUGINPAGEREPLYMESSAGE_H
#define COREMODULES_COMMS_MESSAGETRANSLATERS_TRANSLATEDMESSAGES_PLUGINPAGEREPLYMESSAGE_H
#include "AbstractMessage.h"
#include "../../../exportMacros.h"

namespace TranslatedMessages {

/**
	PluginPageReplyMessage
*/
class DLLCORE_API ReplyMessage : public AbstractMessage
{
private:
	#pragma warning( disable : 4251)
	std::string content;
	#pragma warning( default : 4251)
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



