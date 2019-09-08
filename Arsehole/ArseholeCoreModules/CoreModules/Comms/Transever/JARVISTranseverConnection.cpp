/*
 * arseholeTranseverConnection.cpp
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#include "arseholeTranseverConnection.h"
#include "../Protocals/ChunckedTwoByteMsgLen.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../Comms.h"

arseholeTranseverConnection::arseholeTranseverConnection(boost::asio::io_service& service)
: ITranseverConnection(service)
{


}

arseholeTranseverConnection::~arseholeTranseverConnection() {
	// TODO Auto-generated destructor stub
}

void arseholeTranseverConnection::processConnection()
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

