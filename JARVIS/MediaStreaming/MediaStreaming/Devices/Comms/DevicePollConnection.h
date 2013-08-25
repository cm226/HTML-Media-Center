/*
 * DevicePollConnection.h
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#ifndef DEVICEPOLLCONNECTION_H_
#define DEVICEPOLLCONNECTION_H_

#include "../../../../Comms/Transever/ITranseverConnection.h"

namespace Comms {

class DevicePollConnection : ITranseverConnection
{
public:
	DevicePollConnection(boost::asio::io_service& service);
	virtual ~DevicePollConnection();

	void processConnection();
};

} /* namespace Comms */
#endif /* DEVICEPOLLCONNECTION_H_ */
