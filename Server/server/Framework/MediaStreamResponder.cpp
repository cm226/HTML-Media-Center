/*
 * MediaStreamResponder.cpp
 *
 *  Created on: 22 Aug 2013
 *      Author: craig
 */

#include "MediaStreamResponder.h"
#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../ServerCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.h"
#include "../../ServerCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestReplyMessage.h"
#include <sstream>

MediaStreamResponder::MediaStreamResponder(CoreModules* cm) : _mediaStreamer(cm->getMediaStreamer())
{
	cm->getComms()->messagesubject()->
			onMediaStreamRequestMessageReceved.connect(this,&MediaStreamResponder::mediaStreamRequestHandler);
	cm->getComms()->messagesubject()->
			onAgentRequestMessageReceved.connect(this,&MediaStreamResponder::agentRequestHandler);
}

MediaStreamResponder::~MediaStreamResponder() {
	// TODO Auto-generated destructor stub
}

void MediaStreamResponder::mediaStreamRequestHandler(TranslatedMessages::MediaStreamRequestMessage* msg,
		coremodules::comms::protocals::IProtocal* protocal)
{
	ErrorLogger::logInfo("STREAM DAT MEDIASS");
	std::list<int> mediaIDS = msg->MediaIDs();

	std::stringstream ss;

	for(auto i: mediaIDS)
		ss << i<<",";
	ErrorLogger::logInfo(ss.str());
	protocal->sendMessage(new TranslatedMessages::ReplyMessage("maybe it worked?"));


}

void MediaStreamResponder::agentRequestHandler(TranslatedMessages::AgentRequestMessage* msg
		, coremodules::comms::protocals::IProtocal* protocal)
{
	std::list<AudioDevice> audioDevices;
	_mediaStreamer.Get_Audio_Devices(audioDevices);

	TranslatedMessages::AgentRequestReplyMessage* agentReplyMsg =
			new TranslatedMessages::AgentRequestReplyMessage();

	for(auto agent: audioDevices)
		agentReplyMsg->Add_Agent(agent.Get_Name());

	protocal->sendMessage(agentReplyMsg);
}



