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
#include "../../exportMacros.h"

class DLLCORE_API TCPAsyncTransever
{
private:
	#pragma warning( disable : 4251)
	boost::asio::ip::tcp::acceptor acceptor;
	ITranseverConnectionFactory& connection_factory;
	#pragma warning( default : 4251)

	void handle_accept(boost::shared_ptr<ITranseverConnection> new_connection,
	  const boost::system::error_code& error);

public:
	TCPAsyncTransever(boost::asio::io_service& io_service, int port, ITranseverConnectionFactory& factory);
	virtual ~TCPAsyncTransever();

	
	void start_accept();
};

#endif /* ABSTRACTASYNCTRANSEVER_H_ */
