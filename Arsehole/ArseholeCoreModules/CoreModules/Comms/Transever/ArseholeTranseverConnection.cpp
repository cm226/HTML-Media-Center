/*
 * ArseholeTranseverConnection.cpp
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#include "ArseholeTranseverConnection.h"
#include "../Protocals/ChunckedTwoByteMsgLen.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../Comms.h"

ArseholeTranseverConnection::ArseholeTranseverConnection(boost::asio::io_service& service)
: ITranseverConnection(service)
{


}

ArseholeTranseverConnection::~ArseholeTranseverConnection() {
	// TODO Auto-generated destructor stub
}

void ArseholeTranseverConnection::processConnection()
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

