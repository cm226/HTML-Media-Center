/*
 * DeviceList.cpp
 *
 *  Created on: 24 Aug 2013
 *      Author: craig
 */

#include "DeviceList.h"
#include <boost/asio.hpp>

namespace Devices {

DeviceList::DeviceList() {
	// TODO Auto-generated constructor stub

}

DeviceList::~DeviceList() {
	// TODO Auto-generated destructor stub
}

void DeviceList::Initalise_device_List()
{

	 boost::system::error_code error;
	 boost::asio::ip::udp::socket socket(_impl->_ioService);

	    socket.open(boost::asio::ip::udp::v4(), error);
	    if (!error)
	    {
	        socket.set_option(ba::ip::udp::socket::reuse_address(true));
	        socket.set_option(ba::socket_base::broadcast(true));

	        ba::ip::udp::endpoint senderEndpoint(ba::ip::address_v4::broadcast(), port);

	        socket.send_to(data, senderEndpoint);
	        socket.close(error);
	    }

}

} /* namespace Devices */
