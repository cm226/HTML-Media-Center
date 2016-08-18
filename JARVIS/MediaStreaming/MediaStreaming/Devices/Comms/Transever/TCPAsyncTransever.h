/*
 * AbstractAsyncTransever.h
 *
 *  Created on: 20 May 2013
 *      Author: craig
 */

#pragma once
#ifndef TCPASYNCTRANSEVER_H_
#define TCPASYNCTRANSEVER_H_

#include <boost/asio.hpp>
#include "ITranseverConnectionFactory.h"

class TCPAsyncTransever
{
private:
	boost::asio::ip::tcp::acceptor acceptor;
	MediaStreamingComms::ITranseverConnectionFactory& connection_factory;

	void start_accept();
	void handle_accept(boost::shared_ptr<MediaStreamingComms::ITranseverConnection> new_connection,
	  const boost::system::error_code& error);

public:
	TCPAsyncTransever(boost::asio::io_service& io_service, int port, MediaStreamingComms::ITranseverConnectionFactory& factory);
	virtual ~TCPAsyncTransever();
};

#endif /* ABSTRACTASYNCTRANSEVER_H_ */
