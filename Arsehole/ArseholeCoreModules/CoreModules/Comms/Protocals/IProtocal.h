/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_PROTOCALS_IPROTOCAL_H
#define COREMODULES_COMMS_PROTOCALS_IPROTOCAL_H

#include "../MessageTranslaters/TranslatedMessages/AbstractMessage.h"
#include "../../exportMacros.h"

namespace coremodules {
namespace comms {
namespace protocals {


/**
	IProtocal
*/
class DLLCORE_API IProtocal
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




}
}
}


#endif



