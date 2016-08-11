#include "stdafx.h"

#include "../../JARVISCoreModules/CoreModules/Comms/Transever/TCPTransever.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ListPluginsMessage.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


/*
	IT LOOKS LIKE USING THE BOOST_CHECK_X FUNCTIONS CALSE AN ACCESS VIOLATION IF CALLED FROM ANOTHER THREAD
*/
/*
BOOST_AUTO_TEST_CASE(TCPTranseverConstructorTests)
{
	TCPTransever transever(50000);
}


void ListenForConnection()
{
	TCPTransever transever(50000);
	bool connected = transever.listenForConnection(10);
	BOOST_CHECK_EQUAL(true, connected);
	
	ListPluginsMessage lpMessage;
	transever.sendMessage(&lpMessage);

	transever.shutdown();
}

BOOST_AUTO_TEST_CASE(TCPTranseverSendTests)
{
	boost::thread makeConnectionThread(ListenForConnection);

	boost::this_thread::sleep( boost::posix_time::seconds(1)); // allow the other thread time to setup the transever

	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::endpoint endpoint(
    boost::asio::ip::address::from_string("127.0.0.1"), 50000);
	
	boost::system::error_code ec;
	socket.connect(endpoint, ec);

	BOOST_CHECK_EQUAL(ec.value(),0);
	boost::array<char, 2> buf;
	buf.fill('\0');
	boost::this_thread::sleep( boost::posix_time::seconds(2)); // wate for the other thread to write
	boost::asio::read(socket, boost::asio::buffer(buf));
	int messageSize = buf.at(0);
	messageSize = messageSize << 8;
	messageSize += buf.at(1);

	BOOST_CHECK_EQUAL(messageSize,6);
	
	boost::array<char, 2048> msgBuf;
	msgBuf.fill('\0');
	boost::asio::read(socket, boost::asio::buffer(msgBuf,messageSize));
	std::string message = msgBuf.c_array();
	BOOST_CHECK_EQUAL(message.compare("ppoll$"),0);

	makeConnectionThread.join();
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
	buf[0] = 0; // message size
	buf[1] = 6;
	buf[2] = 'p';
	buf[3] = 'p';
	buf[4] = 'o';
	buf[5] = 'l';
	buf[6] = 'l';
	buf[7] = '$';
	boost::asio::write(socket, boost::asio::buffer(buf));

	socket.shutdown(boost::asio::socket_base::shutdown_both);
}

BOOST_AUTO_TEST_CASE(TCPTranseverReceiveTests)
{
	boost::thread makeConnectionThread(sendMessage);

	TCPTransever transever(50000);
	bool connected = transever.listenForConnection(10);
	BOOST_CHECK_EQUAL(true, connected);
	AbstractMessage* message;
	message = transever.getMessageOrTimeout(5000);
	
	ListPluginsMessage* lpm = dynamic_cast<ListPluginsMessage*>(message);
	BOOST_CHECK_EQUAL(lpm == NULL,false);

	transever.shutdown();
	makeConnectionThread.join();
	
	delete message;
}



void SendLargeString()
{
	TCPTransever transever(50000);
	bool connected = transever.listenForConnection(10);
	BOOST_CHECK_EQUAL(true, connected);
	std::string messageContent(65500,'a');

	TranslatedMessages::ReplyMessage replyMessage(messageContent);
	transever.sendMessage(&replyMessage);

	boost::this_thread::sleep( boost::posix_time::seconds(1) );
	transever.shutdown();
}

BOOST_AUTO_TEST_CASE(TCPTranseverSendLargeString)
{
	boost::thread makeConnectionThread(SendLargeString);
	boost::this_thread::sleep( boost::posix_time::seconds(1)); // allow the other thread time to setup the transever
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::endpoint endpoint(
    boost::asio::ip::address::from_string("127.0.0.1"), 50000);
	
	boost::system::error_code ec;
	socket.connect(endpoint, ec);

	boost::array<unsigned char, 2> buf;
	buf.fill('\0');
	boost::asio::read(socket, boost::asio::buffer(buf,2));
	int messageSize = buf.at(0);
	messageSize = messageSize << 8;
	messageSize += buf.at(1);

	BOOST_CHECK_EQUAL(messageSize,65508);

	boost::array<unsigned char, 65508> bufMsg;
	buf.fill('\0');
	boost::asio::read(socket, boost::asio::buffer(bufMsg,65508),ec);

	makeConnectionThread.join();
	socket.shutdown(boost::asio::socket_base::shutdown_both);

}

BOOST_AUTO_TEST_CASE(BindToAddressAleadyInUse)
{
	TCPTransever transever(50000);

	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::endpoint endpoint(
	boost::asio::ip::address::from_string("127.0.0.1"), 50000);

	socket.bind(endpoint);

	transever.getMessageOrTimeout(100);

}
*/
