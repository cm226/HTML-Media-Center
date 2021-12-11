/*
 * MediaStreamResponder.h
 *
 *  Created on: 22 Aug 2013
 *      Author: craig
 */

#ifndef MEDIASTREAMRESPONDER_H_
#define MEDIASTREAMRESPONDER_H_

#include "../../ServerCoreModules/CoreModules/CoreModules.h"
#include "../../ServerCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/MediaStreamRequestMessage.h"
#include "../../ServerCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestMessage.h"
#include "../../Comms/Protocals/IProtocal.h"

class MediaStreamResponder {
private:
	MediaStreamer& _mediaStreamer;

	void mediaStreamRequestHandler(TranslatedMessages::MediaStreamRequestMessage* msg, coremodules::comms::protocals::IProtocal* protocal);
	void agentRequestHandler(TranslatedMessages::AgentRequestMessage* msg, coremodules::comms::protocals::IProtocal* protocal);

public:
	MediaStreamResponder(CoreModules* cm);
	virtual ~MediaStreamResponder();
};

#endif /* MEDIASTREAMRESPONDER_H_ */