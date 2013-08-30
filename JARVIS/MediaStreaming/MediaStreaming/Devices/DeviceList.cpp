/*
 * DeviceList.cpp
 *
 *  Created on: 24 Aug 2013
 *      Author: craig
 */

#include "DeviceList.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
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

	Broadcaster broadcaster(io_sercive, 40002);
	Comms::DevicePollConnectionFactory connectionFactory(_audio_devices, io_sercive);
	TCPAsyncTransever transever(io_sercive, 40003,connectionFactory);

	boost::thread comms_thread(boost::bind(&boost::asio::io_service::run, &io_sercive));

	io_sercive.poll();
	std::string AGENT_HELLO_BROADCAST;
	AGENT_HELLO_BROADCAST.append(1,7);

	AGENT_HELLO_BROADCAST.append(1,192);
	AGENT_HELLO_BROADCAST.append(1,168);
	AGENT_HELLO_BROADCAST.append(1,0);
	AGENT_HELLO_BROADCAST.append(1,16);
	transever.start_accept();
	broadcaster.Broadcast_Message(AGENT_HELLO_BROADCAST);
	io_sercive.poll();
	boost::this_thread::sleep(boost::posix_time::seconds(10)); // allow 10 sec for agents to respond

	io_sercive.stop();
	comms_thread.join();

}


void DeviceList::Get_Audio_Devices(std::list<AudioDevice>& devices)
{
	for(auto kv : _audio_devices)
		{
			devices.push_back(kv.second);
		}
}


bool DeviceList::Try_Get_Audio_Device_From_ID(AudioDevice& device, int id)
{
	if(_audio_devices.find(id) ==_audio_devices.end())
		return false;

	device = _audio_devices[id];
	return true;
}



} /* namespace Devices */
