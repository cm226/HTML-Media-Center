#include "ChunckedTwoByteMsgLen.h"

#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../../../../Comms/Transever/Exceptions/TimeoutExpiredException.h"

#include <boost/thread.hpp>


ChunckedTwoByteMsgLen::ChunckedTwoByteMsgLen(boost::asio::ip::tcp::socket& socket) : socket(socket),
																					_subprotocal(socket)
{
	this->messageTranslater.setProtocal(this);
}

ChunckedTwoByteMsgLen::~ChunckedTwoByteMsgLen()
{

}

void ChunckedTwoByteMsgLen::constructWholeMessage(char* wholeMsgBuf, std::vector<std::pair<char*, int>> messages)
{
	char* msgBufPrt = wholeMsgBuf;

	for (std::vector<std::pair<char*, int>>::iterator it = messages.begin();
	it != messages.end();
		it++)
	{
		std::copy(it->first, it->first + it->second, msgBufPrt);
		
		delete[] it->first;
		msgBufPrt += it->second;
	}
}

AbstractMessage* ChunckedTwoByteMsgLen::getMessageOrTimeout(unsigned timoutMiliseconds)
{
	boost::asio::socket_base::bytes_readable command(true);
	socket.io_control(command);

	int wateCounter = 0;
	int maxWateTill = (timoutMiliseconds / 1000) + 1;
	std::size_t bytes_readable;
	while ((bytes_readable = command.get()) < 1)
	{
		if (wateCounter > maxWateTill)
		{
			ErrorLogger::logError("Connection Closed due to non responcive end point");
			throw coremodules::comms::transever::exceptions::TimeoutExpiredException("A responce never came from the endfpoint within the timeout time");
			return NULL;
		}
		boost::this_thread::sleep(boost::posix_time::seconds(1));
		socket.io_control(command);
		wateCounter++;
	}

	unsigned char numChuncksBuf;
	numChuncksBuf = 0;
	boost::system::error_code error;
	boost::asio::read(socket, boost::asio::buffer(&numChuncksBuf, 1), error);

	int numChunks = numChuncksBuf;

	if (error.value() != 0)
	{
		ErrorLogger::logError(error.message());
	}

	int messageSize = 0;
	unsigned long wholeMsgSize = 0;

	std::vector<std::pair<char*, int>> wholeMessage;
	for (int i = 0; i < numChunks; i++)
	{
		char* msg = this->_subprotocal.readMsgRaw(timoutMiliseconds, messageSize);
		wholeMessage.push_back(std::pair<char*, int>(msg, messageSize));

		if ((wholeMsgSize + messageSize) < wholeMsgSize) // overflow detection
		{
			ErrorLogger::logError("overflow detected while reading chucked message");
			return NULL;
		}

		wholeMsgSize += messageSize;

	}

	char* wholeMsgBuf = new char[wholeMsgSize];
	this->constructWholeMessage(wholeMsgBuf, wholeMessage);


	return this->messageTranslater.translateMessage(wholeMsgBuf, wholeMsgSize);
}

void ChunckedTwoByteMsgLen::sendMessage(AbstractMessage* data)
{
	this->_subprotocal.sendMessage(data);
}