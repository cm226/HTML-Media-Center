/*
 * Broadcaster.cpp
 *
 *  Created on: 25 Aug 2013
 *      Author: craig
 */

#include "Broadcaster.h"

Broadcaster::Broadcaster(boost::asio::io_service& io_service,  int broadcast_port)
	: _io_service(io_service), _port(broadcast_port)
{
}

Broadcaster::~Broadcaster()
{

}
/*
void Broadcaster::Broadcast_Message(std::string message)
{
	namespace ba = boost::asio;

	boost::system::error_code myError;


	 boost::asio::ip::udp::endpoint targetEndpoint;                  // Create endpoint on specified IP.
	 targetEndpoint.address(boost::asio::ip::address::from_string("127.0.0.1", myError));
	 targetEndpoint.port(40002);

	 boost::asio::ip::udp::socket socket(_io_service);
	 socket.open( targetEndpoint.protocol(), myError );
	 char myMessage[] = {7};                      // Send basig string, enable socket level debugging.
	 socket.send_to(boost::asio::buffer(myMessage, sizeof(myMessage)), targetEndpoint, boost::asio::socket_base::debug(true), myError);


	 int i = 0;
	 i++;
}*/


void Broadcaster::Broadcast_Message(std::string message)
{
	namespace ba = boost::asio;

	boost::system::error_code error;
	ba::ip::udp::socket socket(_io_service);

	socket.open(boost::asio::ip::udp::v4(), error);
	if (!error)
	{
		socket.set_option(ba::ip::udp::socket::reuse_address(true));
		socket.set_option(ba::socket_base::broadcast(true));

		ba::ip::udp::endpoint senderEndpoint(ba::ip::address_v4::broadcast(), _port);

		socket.send_to(boost::asio::buffer(message) , senderEndpoint);
		socket.close(error);
	}

}

