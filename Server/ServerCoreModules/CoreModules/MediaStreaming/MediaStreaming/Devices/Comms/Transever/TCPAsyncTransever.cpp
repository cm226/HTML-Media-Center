/*
 * AbstractAsyncTransever.cpp
 *
 *  Created on: 20 May 2013
 *      Author: craig
 */

#include "TCPAsyncTransever.h"
#include "ITranseverConnection.h"
#include <boost/bind.hpp>


using namespace boost::asio::ip;

TCPAsyncTransever::TCPAsyncTransever(boost::asio::io_service& io_service, int port, MediaStreamingComms::ITranseverConnectionFactory& factory) :
	acceptor(io_service, tcp::endpoint(tcp::v4(), port)), connection_factory(factory)
{
	start_accept();
}

TCPAsyncTransever::~TCPAsyncTransever()
{

}

void TCPAsyncTransever::start_accept()
{
	boost::shared_ptr<MediaStreamingComms::ITranseverConnection> new_connection =
			this->connection_factory.create(acceptor.get_io_service());

	acceptor.async_accept(new_connection->socket(),
	        boost::bind(&TCPAsyncTransever::handle_accept, this, new_connection,
	          boost::asio::placeholders::error));
}

void TCPAsyncTransever::handle_accept(boost::shared_ptr<MediaStreamingComms::ITranseverConnection> new_connection,
  const boost::system::error_code& error)
{
	if (!error)
	{
	  new_connection->processConnection();
	  start_accept();
	}
}


