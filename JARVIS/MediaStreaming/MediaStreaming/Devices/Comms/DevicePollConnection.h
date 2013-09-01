/*
 * DevicePollConnection.h
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#ifndef DEVICEPOLLCONNECTION_H_
#define DEVICEPOLLCONNECTION_H_

#include <list>
#include <string>

#include "Transever/ITranseverConnection.h"
#include "../AudioDevice.h"

namespace Comms {

class DevicePollConnection : public MediaStreamingComms::ITranseverConnection
{
private:
	std::list<AudioDevice>& _device_list;

	std::string parseIP(std::string& buff);
	void createAudioDevice(std::string& ip);
public:
	DevicePollConnection(boost::asio::io_service& service, std::list<AudioDevice>& deviceList);
	virtual ~DevicePollConnection();

	void processConnection();
};

} /* namespace Comms */
#endif /* DEVICEPOLLCONNECTION_H_ */
