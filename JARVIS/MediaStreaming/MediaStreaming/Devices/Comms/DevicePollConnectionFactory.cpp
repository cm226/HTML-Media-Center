/*
 * DevicePollConnectionFactory.cpp
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#include "DevicePollConnectionFactory.h"
#include "DevicePollConnection.h"


namespace Comms {

DevicePollConnectionFactory::DevicePollConnectionFactory(std::list<AudioDevice>& device_List,
																boost::asio::io_service& io_service)
	:_device_List(device_List),
	 _io_service(io_service)
{

}

DevicePollConnectionFactory::~DevicePollConnectionFactory()
{

}

boost::shared_ptr<MediaStreamingComms::ITranseverConnection> DevicePollConnectionFactory::create(
		boost::asio::io_service& service)
{
	return boost::shared_ptr<MediaStreamingComms::ITranseverConnection>(new DevicePollConnection(_io_service, _device_List));
}

} /* namespace Comms */
