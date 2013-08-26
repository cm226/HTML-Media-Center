/*
 * DeviceList.cpp
 *
 *  Created on: 24 Aug 2013
 *      Author: craig
 */

#include "DeviceList.h"
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

#include "Comms/DevicePollConnectionFactory.h"
#include "../../../Comms/Broadcaster.h"
#include "../../../Comms/Transever/TCPAsyncTransever.h"

namespace Devices {

DeviceList::DeviceList() {
	// TODO Auto-generated constructor stub

}

DeviceList::~DeviceList() {
	// TODO Auto-generated destructor stub
}

void DeviceList::Initalise_device_List()
{
	boost::asio::io_service io_sercive;

	Broadcaster broadcaster(io_sercive, 1001);
	Comms::DevicePollConnectionFactory connectionFactory;
	TCPAsyncTransever transever(io_sercive, 1002,connectionFactory);
	boost::thread comms_thread(io_sercive.run());

	std::string AGENT_HELLO_BROADCAST;
	AGENT_HELLO_BROADCAST.append(1,7);
	broadcaster.Broadcast_Message(AGENT_HELLO_BROADCAST);

	boost::this_thread::sleep( boost::chrono::seconds(10) ); // allow 10 sec for agents to respond

	io_sercive.stop();
	comms_thread.join();

}

} /* namespace Devices */
