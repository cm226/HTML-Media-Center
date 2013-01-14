/*
 * TCPTransever.h
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#ifndef TCPTRANSEVER_H_
#define TCPTRANSEVER_H_

#include "AbstractTransever.h"
#include <boost/asio.hpp>

class TCPTransever : public AbstractTransever{

	bool stopped_;

public:
	static const int PORT = 45001;
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket* curSocket;
	boost::asio::deadline_timer* timer;


	TCPTransever();
	virtual ~TCPTransever();


	virtual int listenForConnection(int timeout);
	virtual void getMessage(std::string* data);
	virtual void sendMessage(std::string* data);

private:
	void check_deadline();
};

#endif /* TCPTRANSEVER_H_ */
