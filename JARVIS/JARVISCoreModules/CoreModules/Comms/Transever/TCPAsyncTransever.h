/*
 * AbstractAsyncTransever.h
 *
 *  Created on: 20 May 2013
 *      Author: craig
 */

#ifndef TCPASYNCTRANSEVER_H_
#define TCPASYNCTRANSEVER_H_

#include <boost/asio.hpp>
#include "TranseverConnectionFactory.h"

class TCPAsyncTransever
{
private:
	boost::asio::ip::tcp::acceptor acceptor;
	TranseverConnectionFactory& connection_factory;

	void start_accept();
	void handle_accept(boost::shared_ptr<ITranseverConnection> new_connection,
	  const boost::system::error_code& error);

public:
	TCPAsyncTransever(boost::asio::io_service& io_service, int port, TranseverConnectionFactory& factory);
	virtual ~TCPAsyncTransever();
};

#endif /* ABSTRACTASYNCTRANSEVER_H_ */
