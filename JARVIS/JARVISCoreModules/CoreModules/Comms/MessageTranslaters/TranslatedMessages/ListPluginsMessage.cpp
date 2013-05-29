/*
 * ListPluginsMessage.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: craig
 */

#include "ListPluginsMessage.h"
#include "ReplyMessage.h"
#include <vector>

using namespace std;

ListPluginsMessage::ListPluginsMessage(char* data, unsigned int length):AbstractMessage(data,length) {

}

ListPluginsMessage::ListPluginsMessage()
{

}

ListPluginsMessage::~ListPluginsMessage() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* ListPluginsMessage::actionMessage()
{
	vector<vector<string> > pluginReplys;

	EventManager::pluginPoll.notify(100,&pluginReplys);
	std::string reply;
	reply = "%Miscellaneous";
	for(vector<vector<string> >::iterator it = pluginReplys.begin(); it != pluginReplys.end(); it++)
	{
		for(vector<string>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			reply.append(",").append(*it2).append(",%Miscellaneous");
		}
	}

	return new TranslatedMessages::ReplyMessage(reply);
}

void ListPluginsMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{
	serialiser.serialiseValue(this->getHeader());
}

 std::string ListPluginsMessage::getHeader()
 {
	 return "ppoll";
 }

