#include "stdafx.h"
#include <boost/thread.hpp>
#include <boost/array.hpp>

#include "../../JARVISCoreModules/CoreModules/Comms/Protocals/TwoByteMsgLen.h"
#include "../../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ListPluginsMessage.h"

void sendMessage()
{
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::endpoint endpoint(
    boost::asio::ip::address::from_string("127.0.0.1"), 50000);
	
	boost::system::error_code ec;
	boost::this_thread::sleep(boost::posix_time::seconds(1)); // allow the acceptor to be created
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

BOOST_AUTO_TEST_CASE(recv2ByeMsgTest)
{
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 50000));
	acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));

	boost::thread makeConnectionThread(sendMessage);
	acceptor.accept(socket);

	TwoByteMsgLen msgProtocal(socket);
	AbstractMessage* msg = msgProtocal.getMessageOrTimeout(1000);
	ListPluginsMessage* lpm = dynamic_cast<ListPluginsMessage*>(msg);

	BOOST_CHECK_NE(lpm ==NULL, true);
	makeConnectionThread.join();

	delete lpm;
}