#include "stdafx.h"
#include "../../Transever/TCPTransever.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost\array.hpp>

/*
	IT LOOKS LIKE USING THE BOOST_CHECK FUNCTIONS CALSE AN ACES VIOLATION IF CALLED FROM ANOTHER THREAD
*/

BOOST_AUTO_TEST_CASE(TCPTranseverConstructorTests)
{
	TCPTransever transever(50000);
}


void ListenForConnection()
{
	TCPTransever transever(50000);
	bool connected = transever.listenForConnection(1000);
	BOOST_CHECK_EQUAL(true, connected);

	std::string message = "this is a test Message";

	transever.sendMessage(&message);

	transever.shutdown();
}

BOOST_AUTO_TEST_CASE(TCPTranseverSendTests)
{
	boost::thread makeConnectionThread(ListenForConnection);

	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::endpoint endpoint(
    boost::asio::ip::address::from_string("127.0.0.1"), 50000);
	
	boost::system::error_code ec;
	socket.connect(endpoint, ec);

	boost::array<char, 1024> buf;
	buf.fill('\0');
	boost::asio::read(socket, boost::asio::buffer(buf), ec);
	std::string reply (buf.c_array());
	BOOST_CHECK_EQUAL(reply.compare("this is a test Message"),0);
	socket.shutdown(boost::asio::socket_base::shutdown_both);

}

void sendMessage()
{
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::endpoint endpoint(
    boost::asio::ip::address::from_string("127.0.0.1"), 50000);
	
	boost::system::error_code ec;

	boost::this_thread::sleep( boost::posix_time::seconds(1) ); // wate for the transever to be created in the other thread
	socket.connect(endpoint, ec);

	boost::array<char, 1024> buf;
	buf.fill('\0');
	boost::asio::write(socket, boost::asio::buffer("this is a test Message"), ec);

	socket.shutdown(boost::asio::socket_base::shutdown_both);
}

BOOST_AUTO_TEST_CASE(TCPTranseverReceiveTests)
{
	boost::thread makeConnectionThread(sendMessage);

	TCPTransever transever(50000);
	bool connected = transever.listenForConnection(1000);
	BOOST_CHECK_EQUAL(true, connected);
	std::string message;
	BOOST_CHECK_NO_THROW(transever.getMessageOrTimeout(&message,5000));
	BOOST_CHECK_EQUAL(message.compare("this is a test Message"),0);
	
	transever.shutdown();
}



void SendLargeString()
{
	TCPTransever transever(50000);
	bool connected = transever.listenForConnection(1000);
	BOOST_CHECK_EQUAL(true, connected);
	std::string message(100000,'a');

	transever.sendMessage(&message);

	transever.shutdown();
}

BOOST_AUTO_TEST_CASE(TCPTranseverSendLargeString)
{
	boost::thread makeConnectionThread(SendLargeString);

	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::endpoint endpoint(
    boost::asio::ip::address::from_string("127.0.0.1"), 50000);
	
	boost::system::error_code ec;
	socket.connect(endpoint, ec);
	unsigned numOfChunks = (100000 / 2048) +1;

	boost::array<char, 2048> buf;
	std::string expectedReply(2048,'a');
	expectedReply.append("\0");

	while(numOfChunks > 0)
	{
		buf.fill('\0');
		boost::asio::read(socket, boost::asio::buffer(buf), ec);
		std::string reply (buf.c_array());
		reply.resize(2048);
		BOOST_CHECK_EQUAL(expectedReply.compare(reply),0);

		boost::asio::write(socket, boost::asio::buffer("RnextChunk$"), ec);
		std::string error = ec.message();
		numOfChunks--;
	}
	socket.shutdown(boost::asio::socket_base::shutdown_both);

}