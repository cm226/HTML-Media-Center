/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESUBJECT_MESSAGESUBJECT_H
#define COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESUBJECT_MESSAGESUBJECT_H

#include "../TranslatedMessages/ListPluginsMessage.h"
#include "../TranslatedMessages/PluginPageMessage.h"
#include "../TranslatedMessages/PluginInteractionRequestMessage.h"
#include "../TranslatedMessages/MobilePluginPageMessage.h"
#include "../TranslatedMessages/MediaStreamRequestMessage.h"

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
	MessageSubjectEvent<TranslatedMessages::PluginPageMessage> onPluginPageMessageReceved;
	MessageSubjectEvent<TranslatedMessages::PluginInteractionRequestMessage> onPluginInteractionMessageReceved;
	MessageSubjectEvent<TranslatedMessages::MobilePluginPageMessage> onMobilePluginPageMessageReceved;
	MessageSubjectEvent<TranslatedMessages::MediaStreamRequestMessage> onMediaStreamRequestMessageReceved;

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



