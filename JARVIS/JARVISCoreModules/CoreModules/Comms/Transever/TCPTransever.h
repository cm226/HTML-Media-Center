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
#include "Exceptions/TimeoutExpiredException.h"
#include "../MessageTranslaters/Translater.h"
#include "../MessageTranslaters/TranslatedMessages/TranslatedMessages.h"


class TCPTransever : public AbstractTransever{

	bool stopped_;

private :
	int PORT;
	Translater messageTranslater;

	void sendMessageChunks(std::list<std::string>& chunks);

	bool isRequestNextDataMessage(AbstractMessage* msg);

public:
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket* curSocket;
	boost::asio::deadline_timer* timer;

	TCPTransever(int port);
	virtual ~TCPTransever();


	virtual bool listenForConnection(int timeout);
	virtual AbstractMessage* getMessageOrTimeout(unsigned timoutMiliseconds);
	virtual void sendMessage( AbstractMessage* message);
	void shutdown();

private:
	void check_deadline();
};

#endif /* TCPTRANSEVER_H_ */
