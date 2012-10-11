/*
 * ListPluginsMessage.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: craig
 */

#include "ListPluginsMessage.h"

#include <vector>

using namespace std;

ListPluginsMessage::ListPluginsMessage(const char* data, unsigned int length):AbstractMessage(data,length) {

}

ListPluginsMessage::~ListPluginsMessage() {
	// TODO Auto-generated destructor stub
}

void ListPluginsMessage::actionMessage(std::string* reply,EventManager* evntMan)
{
	vector<vector<string> > pluginReplys;

	evntMan->pluginPoll.notify(100,&pluginReplys);

	for(vector<vector<string> >::iterator it = pluginReplys.begin(); it != pluginReplys.end(); it++)
	{
		for(vector<string>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			reply->append(*it2).append(",");
	}

	return;

}

