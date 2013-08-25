/*
 * Broadcaster.h
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#ifndef BROADCASTER_H_
#define BROADCASTER_H_

#include "exportMacros.h"
#include <boost/asio.hpp>


class COMMS_API Broadcaster {
private:
	boost::asio::io_service& _io_service;
	int _port;
public:
	Broadcaster(boost::asio::io_service& io_service,  int broadcast_port);
	virtual ~Broadcaster();

	void Broadcast_Message(std::string message);


};

#endif /* BROADCASTER_H_ */
