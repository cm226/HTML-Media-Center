/*
 * JARVISTranseverConnection.cpp
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#include "JARVISTranseverConnection.h"
#include "../Protocals/TwoByteMsgLen.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../Comms.h"

JARVISTranseverConnection::JARVISTranseverConnection(boost::asio::io_service& service)
: ITranseverConnection(service)
{


}

JARVISTranseverConnection::~JARVISTranseverConnection() {
	// TODO Auto-generated destructor stub
}

void JARVISTranseverConnection::processConnection()
{
	TwoByteMsgLen msgProtocal(this->socket());

	AbstractMessage* msg = msgProtocal.getMessageOrTimeout(1000);
	if(msg == NULL)
	{
		ErrorLogger::logError("connection Timed out");
		return;
	}
	delete msg;
}

