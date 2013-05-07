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
#include <list>
 #include "Exceptions\TimeoutExpiredException.h"


class TCPTransever : public AbstractTransever{

	bool stopped_;

private :
	int PORT;

	void sendMessageChunks(std::list<std::string>& chunks);

public:
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket* curSocket;
	boost::asio::deadline_timer* timer;

	TCPTransever(int port);
	virtual ~TCPTransever();


	virtual bool listenForConnection(int timeout);
	virtual void getMessageOrTimeout(std::string* data, unsigned timoutMiliseconds);
	virtual void sendMessage(std::string* data);
	void shutdown();

private:
	void check_deadline();
};

#endif /* TCPTRANSEVER_H_ */
