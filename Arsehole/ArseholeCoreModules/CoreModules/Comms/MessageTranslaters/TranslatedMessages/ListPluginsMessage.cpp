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


void ListPluginsMessage::serialize(coremodules::comms::messagetranslaters::StringMessageSerializer& serialiser)
{
	serialiser.serialiseValue(this->getHeader());
}

 std::string ListPluginsMessage::getHeader()
 {
	 return "ppoll";
 }

