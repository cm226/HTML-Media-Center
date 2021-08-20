/*
 * ServerTranseverConnection.cpp
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#include "ServerTranseverConnection.h"
#include "../Protocals/ChunckedTwoByteMsgLen.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../Comms.h"

ServerTranseverConnection::ServerTranseverConnection(boost::asio::io_service& service)
: ITranseverConnection(service)
{


}

ServerTranseverConnection::~ServerTranseverConnection() {
	// TODO Auto-generated destructor stub
}

void ServerTranseverConnection::processConnection()
{
	ChunckedTwoByteMsgLen msgProtocal(this->socket());

	AbstractMessage* msg = msgProtocal.getMessageOrTimeout(1000);
	if(msg == NULL)
	{
		ErrorLogger::logError("connection Timed out");
		return;
	}
	delete msg;
}

