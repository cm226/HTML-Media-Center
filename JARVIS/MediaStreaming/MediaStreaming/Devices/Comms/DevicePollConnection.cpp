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

DevicePollConnection::DevicePollConnection(boost::asio::io_service& service, std::list<AudioDevice>& deviceList) :
		ITranseverConnection(service),
		_device_list(deviceList)
{
}

DevicePollConnection::~DevicePollConnection()
{
}


void DevicePollConnection::processConnection()
{
	char header;
	boost::asio::mutable_buffer buff(&header,1);
	this->socket_.read_some(buff);

	if(buff[0] == AGENT_HELLO_REPLY)
	{
		char address[4];
		boost::asio::mutable_buffer ip_address(address, 4);

		this->socket_.read_some(buff); // skip the comma
		this->socket_.read_some(ip_address);
		createAudioDevice(ip_address);
	}
	else
		ErrorLogger::logError("Received a message with bad header to device poll in media streaming");
}

void DevicePollConnection::createAudioDevice(boost::asio::mutable_buffer& ip)
{
	AudioDevice newDevice;
	std::string parsed_device_IP = parsed_device_IP(ip);
	newDevice.Set_IP(parsed_device_IP);
	_device_list.push_back(newDevice);
	ErrorLogger::logInfo("Device Registered with ip: "+parsed_device_IP);
}
std::string DevicePollConnection::parseIP(boost::asio::mutable_buffer& buff)
{
	std::stringstream ip;
	ip << buff[0] << '.' << buff[1] << '.' << buff[2] << '.' << buff[3];
	return ip.str();
}

} /* namespace Comms */
