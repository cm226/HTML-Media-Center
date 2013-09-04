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

<<<<<<< HEAD
DevicePollConnection::DevicePollConnection(boost::asio::io_service& service, std::unordered_map<int,AudioDevice>& deviceList) :
		ITranseverConnection(service),
=======
DevicePollConnection::DevicePollConnection(boost::asio::io_service& service, std::unordered_map<int, AudioDevice>& deviceList) :
		MediaStreamingComms::ITranseverConnection(service),
>>>>>>> f4855cc0357f94ea74b95d110b8d2209c43a1b07
		_device_list(deviceList)
{
}

DevicePollConnection::~DevicePollConnection()
{
}


void DevicePollConnection::processConnection()
{
	char header[1];
	this->socket_.read_some(boost::asio::buffer(header));

	if(header[0] == AGENT_HELLO_REPLY)
	{
		char ip_address[4];
		this->socket_.read_some(boost::asio::buffer(ip_address));

		std::string addressStr(ip_address);
		createAudioDevice(addressStr);
	}
	else
		ErrorLogger::logError("Received a message with bad header to device poll in media streaming");
}

void DevicePollConnection::createAudioDevice(std::string& ip)
{
	AudioDevice newDevice;
	std::string parsed_device_IP = parseIP(ip);
	newDevice.Set_IP(parsed_device_IP);
<<<<<<< HEAD
	_device_list[newDevice.getID()] = newDevice;
=======
	_device_list[newDevice.getID()]  = (newDevice);
>>>>>>> f4855cc0357f94ea74b95d110b8d2209c43a1b07
	ErrorLogger::logInfo("Device Registered with ip: "+parsed_device_IP);
}
std::string DevicePollConnection::parseIP(std::string& buff)
{
	std::stringstream ip;
	ip << buff[0] << '.' << buff[1] << '.' << buff[2] << '.' << buff[3];
	return ip.str();
}

} /* namespace Comms */
