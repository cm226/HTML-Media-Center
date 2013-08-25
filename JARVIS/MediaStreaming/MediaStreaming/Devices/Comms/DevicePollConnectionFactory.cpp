/*
 * DevicePollConnectionFactory.cpp
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#include "DevicePollConnectionFactory.h"

namespace Comms {

DevicePollConnectionFactory::DevicePollConnectionFactory() {
	// TODO Auto-generated constructor stub

}

DevicePollConnectionFactory::~DevicePollConnectionFactory() {
	// TODO Auto-generated destructor stub
}

boost::shared_ptr<ITranseverConnection> DevicePollConnectionFactory::create(
		boost::asio::io_service& service)
{

}

} /* namespace Comms */
