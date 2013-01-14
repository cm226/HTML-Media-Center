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

private :
	int PORT;

public:
<<<<<<< HEAD
	static const int PORT = 45001;
=======

>>>>>>> ca06a02b059deda0b65a4fdef1d93f4f075b040d
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket* curSocket;
	boost::asio::deadline_timer* timer;


	TCPTransever(int port);
	virtual ~TCPTransever();


	virtual int listenForConnection(int timeout);
	virtual void getMessage(std::string* data);
	virtual void sendMessage(std::string* data);

private:
	void check_deadline();
};

#endif /* TCPTRANSEVER_H_ */
