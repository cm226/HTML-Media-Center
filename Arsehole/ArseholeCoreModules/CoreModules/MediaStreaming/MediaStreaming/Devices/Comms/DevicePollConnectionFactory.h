/*
 * DevicePollConnectionFactory.h
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#ifndef DEVICEPOLLCONNECTIONFACTORY_H_
#define DEVICEPOLLCONNECTIONFACTORY_H_

#include <unordered_map>

#include "Transever/ITranseverConnectionFactory.h"
#include "../AudioDevice.h"

namespace Comms {

class DevicePollConnectionFactory :public MediaStreamingComms::ITranseverConnectionFactory
{
private:
	std::unordered_map<int, AudioDevice>& _device_List;
	boost::asio::io_service& _io_service;

public:
	DevicePollConnectionFactory(std::unordered_map<int, AudioDevice>& _device_List,boost::asio::io_service& io_service);
	virtual ~DevicePollConnectionFactory();

	boost::shared_ptr<MediaStreamingComms::ITranseverConnection> create(boost::asio::io_service& service);
};

} /* namespace Comms */
#endif /* DEVICEPOLLCONNECTIONFACTORY_H_ */
