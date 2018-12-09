/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_PROTOCALS_IPROTOCAL_H
#define COREMODULES_COMMS_PROTOCALS_IPROTOCAL_H

#include "../MessageTranslaters/TranslatedMessages/AbstractMessage.h"


/**
	IProtocal
*/
class IProtocal
{
public:
	/**
		ctor
	*/
	IProtocal();

	/**
		dtor
	*/
	~IProtocal();

	virtual AbstractMessage* getMessageOrTimeout(unsigned timoutMiliseconds) = 0;
	virtual void sendMessage( AbstractMessage* data) = 0;

};




#endif



