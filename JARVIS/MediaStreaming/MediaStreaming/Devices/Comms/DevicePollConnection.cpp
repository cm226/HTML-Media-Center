/*
 * DevicePollConnection.cpp
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#include "DevicePollConnection.h"

namespace Comms {

DevicePollConnection::DevicePollConnection(boost::asio::io_service& service) :
		ITranseverConnection(service)
{
	// TODO Auto-generated constructor stub

}

DevicePollConnection::~DevicePollConnection() {
	// TODO Auto-generated destructor stub
}


void DevicePollConnection::processConnection()
{

}

} /* namespace Comms */
