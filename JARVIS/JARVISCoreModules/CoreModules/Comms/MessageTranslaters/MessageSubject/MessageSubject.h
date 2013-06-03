/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESUBJECT_MESSAGESUBJECT_H
#define COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESUBJECT_MESSAGESUBJECT_H

#include "../TranslatedMessages/ListPluginsMessage.h"
#include "MessageSubjectEvent.h"

namespace coremodules {
namespace comms {
namespace messagetranslaters {
namespace messagesubject {


/**
	MessageSubject
*/
class DLLCORE_API MessageSubject
{
public:

	MessageSubjectEvent<ListPluginsMessage> onListPluginsMessageReceved;
	/**
		ctor
	*/
	MessageSubject();

	/**
		dtor
	*/
	~MessageSubject();

};




}
}
}
}


#endif



