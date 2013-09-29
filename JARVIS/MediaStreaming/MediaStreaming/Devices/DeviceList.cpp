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
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <sstream>
#include <vector>


#include "Comms/DevicePollConnectionFactory.h"
#include "../../../Comms/Broadcaster.h"
#include "Comms/Transever/TCPAsyncTransever.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"
#include "Comms/IPGetter.h"

namespace Devices {

DeviceList::DeviceList() {


}

DeviceList::~DeviceList() {
	// TODO Auto-generated destructor stub
}

void DeviceList::Initalise_device_List()
{
	_audio_devices.clear();
	boost::thread agentPollSevice(boost::bind(&DeviceList::wate_for_AgentReplys, this));
	
}

void DeviceList::wate_for_AgentReplys()
{
	
	boost::asio::io_service io_sercive;
	Broadcaster broadcaster(io_sercive, 40002);
	Comms::DevicePollConnectionFactory connectionFactory(_audio_devices, io_sercive);

	TCPAsyncTransever transever(io_sercive, 40003,connectionFactory); // handles any responces to the Agent Hello Broadcast
	boost::thread comms_thread(boost::bind(&boost::asio::io_service::run, &io_sercive)); // start the comms Service

	std::string AGENT_HELLO_BROADCAST = build_Broadcast_Message();

	broadcaster.Broadcast_Message(AGENT_HELLO_BROADCAST);

	boost::this_thread::sleep(boost::posix_time::seconds(10)); // allow 10 sec for agents to respond
	std::stringstream infoMsg;
	infoMsg << "Finished Listening for Agents, collected : " << _audio_devices.size() << " device(s)";
	ErrorLogger::logInfo(infoMsg.str());
	io_sercive.stop();
	comms_thread.join();
}


std::string DeviceList::build_Broadcast_Message()
{

	Comms::IPGetter ipgetter;
	std::string lanIP = ipgetter.getLANIP();

	std::vector<std::string> strs;
	boost::split(strs,lanIP,boost::is_any_of("."));

	if(strs.size() != 4)
	{
		ErrorLogger::logError("Weird IP returned form IP getter returning localhost: "+lanIP);
		return "";
	}

	std::string AGENT_HELLO_BROADCAST;

	unsigned char p1 = (unsigned char)atoi(strs[0].c_str());
	unsigned char p2 = (unsigned char)atoi(strs[1].c_str());
	unsigned char p3 = (unsigned char)atoi(strs[2].c_str());
	unsigned char p4 = (unsigned char)atoi(strs[3].c_str());


	AGENT_HELLO_BROADCAST.append(1,7);

	AGENT_HELLO_BROADCAST.append(1,p1);
	AGENT_HELLO_BROADCAST.append(1,p2);
	AGENT_HELLO_BROADCAST.append(1,p3);
	AGENT_HELLO_BROADCAST.append(1,p4);

	return AGENT_HELLO_BROADCAST;
}

void DeviceList::Get_Audio_Devices(std::list<AudioDevice>& audio_Devices)
{
	for(auto audio_device : _audio_devices)
		audio_Devices.push_back(audio_device.second);
}

bool DeviceList::Try_Get_Audio_Device_From_ID(AudioDevice& device, int id)
{
	if(_audio_devices.find(id) == _audio_devices.end())
		return false;

	device = _audio_devices[id];
	return true;
}

} /* namespace Devices */
