/*
 * DevicePollConnection.h
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#ifndef DEVICEPOLLCONNECTION_H_
#define DEVICEPOLLCONNECTION_H_

#include <unordered_map>
#include <string>

#include "../../../../Comms/Transever/ITranseverConnection.h"
#include "../AudioDevice.h"

namespace Comms {

class DevicePollConnection : public ITranseverConnection
{
private:
	std::unordered_map<int,AudioDevice>& _device_list;

	std::string parseIP(std::string& buff);
	void createAudioDevice(std::string& ip);
public:
	DevicePollConnection(boost::asio::io_service& service, std::unordered_map<int,AudioDevice>& deviceList);
	virtual ~DevicePollConnection();

	void processConnection();
};

} /* namespace Comms */
#endif /* DEVICEPOLLCONNECTION_H_ */
