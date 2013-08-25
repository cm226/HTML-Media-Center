/*
 * DevicePollConnectionFactory.h
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#ifndef DEVICEPOLLCONNECTIONFACTORY_H_
#define DEVICEPOLLCONNECTIONFACTORY_H_

#include "../../../../Comms/Transever/ITranseverConnectionFactory.h"

namespace Comms {

class DevicePollConnectionFactory : ITranseverConnectionFactory
{
public:
	DevicePollConnectionFactory();
	virtual ~DevicePollConnectionFactory();

	boost::shared_ptr<ITranseverConnection> create(boost::asio::io_service& service);
};

} /* namespace Comms */
#endif /* DEVICEPOLLCONNECTIONFACTORY_H_ */
