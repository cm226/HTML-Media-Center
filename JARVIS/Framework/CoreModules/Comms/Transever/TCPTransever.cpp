/*
 * TCPTransever.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#include "TCPTransever.h"

using boost::asio::ip::tcp;



TCPTransever::TCPTransever()
{
}

TCPTransever::~TCPTransever()
{

}


int TCPTransever::listenForConnection(int timeout)
{
	tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

	 tcp::socket socket(io_service);
	 acceptor.accept(socket);

	 boost::system::error_code ignored_error;
	 boost::asio::write(socket, boost::asio::buffer("testMessage"),boost::asio::transfer_all(), ignored_error);


	return 1;
}
