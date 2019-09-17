/*
 * AgentRequestReplyMessage.cpp
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#include "AgentRequestReplyMessage.h"

namespace TranslatedMessages {

AgentRequestReplyMessage::AgentRequestReplyMessage() {
	// TODO Auto-generated constructor stub

}

AgentRequestReplyMessage::~AgentRequestReplyMessage() {
	// TODO Auto-generated destructor stub
}

void AgentRequestReplyMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{
	std::stringstream ss;
	serialiser.serialiseValue(getHeader());
	for(auto agent: _agents)
		ss << agent << ",";

	serialiser.serialiseValue(ss.str());
}

void AgentRequestReplyMessage::Add_Agent(std::string agent)
{
	_agents.push_back(agent);
}


std::string AgentRequestReplyMessage::getHeader()
{
	return "ARRM";
}


} /* namespace TranslatedMessages */
