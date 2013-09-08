/*
 * DevicePollConnection.cpp
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#include "DevicePollConnection.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include <sstream>

#define AGENT_HELLO_REPLY 8

namespace Comms {

DevicePollConnection::DevicePollConnection(boost::asio::io_service& service, std::unordered_map<int, AudioDevice>& deviceList) :
		MediaStreamingComms::ITranseverConnection(service),
		_device_list(deviceList)
{
}

DevicePollConnection::~DevicePollConnection()
{
}


void DevicePollConnection::processConnection()
{
	unsigned char header[1];
	this->socket_.read_some(boost::asio::buffer(header));

	if(header[0] == AGENT_HELLO_REPLY)
	{
		unsigned char ip_address[4];
		this->socket_.read_some(boost::asio::buffer(ip_address));
		createAudioDevice(ip_address);
	}
	else
		ErrorLogger::logError("Received a message with bad header to device poll in media streaming");
}

void DevicePollConnection::createAudioDevice(unsigned char ip_address[4])
{
	AudioDevice newDevice;
	std::string parsed_device_IP = parseIP(ip_address);
	newDevice.Set_IP(parsed_device_IP);
	_device_list[newDevice.getID()]  = newDevice;
	ErrorLogger::logInfo("Device Registered with ip: "+parsed_device_IP);
}
std::string DevicePollConnection::parseIP(unsigned char ip_address[4])
{
	std::stringstream ip;
	ip << (int)ip_address[0] << '.' << (int)ip_address[1] << '.' << (int)ip_address[2] << '.' << (int)ip_address[3];
	return ip.str();
}

} /* namespace Comms */
