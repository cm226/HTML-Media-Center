/*
 * TwoByteMsgLen.cpp
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#include "TwoByteMsgLen.h"
#include "../../Errors/ErrorLogger.h"
#include "../Transever/Exceptions/TimeoutExpiredException.h"
#include "../Transever/MessageChunker.h"

#include <boost/thread.hpp>

TwoByteMsgLen::TwoByteMsgLen(boost::asio::ip::tcp::socket& socket) : socket(socket)
{
	messageTranslater.setProtocal(this);
}

TwoByteMsgLen::~TwoByteMsgLen()
{

}



AbstractMessage* TwoByteMsgLen::getMessageOrTimeout(unsigned timoutMiliseconds)
{
	boost::asio::socket_base::bytes_readable command(true);
	socket.io_control(command);

	int wateCounter = 0;
	int maxWateTill = (timoutMiliseconds /1000)+1;
	std::size_t bytes_readable;
	while((bytes_readable = command.get()) < 2)
	{
		if(wateCounter > maxWateTill)
		{
			ErrorLogger::logError("Connection Closed due to non responcive end point");
			throw coremodules::comms::transever::exceptions::TimeoutExpiredException("A responce never came from the endfpoint within the timeout time");
			return NULL;
		}
		boost::this_thread::sleep( boost::posix_time::seconds(1) );
		socket.io_control(command);
		wateCounter++;
	}

	unsigned char* msgSize = new unsigned char[2];
	boost::system::error_code error;
	boost::asio::read(socket,boost::asio::buffer(msgSize,2),error);

	int messageSize = msgSize[0];
	messageSize = messageSize << 8;
	messageSize += msgSize[1];

	std::cout << error;
	char* accualMessage = new char[messageSize+1];
	boost::asio::read(socket,boost::asio::buffer(accualMessage,messageSize),error);
	accualMessage[messageSize] = '\0';

	AbstractMessage* message =  this->messageTranslater.translateMessage(accualMessage,messageSize);
	delete[] msgSize;
	return message;
}

void TwoByteMsgLen::sendMessage( AbstractMessage* data)
{
	if(this->socket.is_open())
	{
		coremodules::comms::messagetranslaters::StringMessageSerializer serializer;
		data->serialize(serializer);
		std::list<std::string> messageChunks;
		std::string messageContent = serializer.serialize();


		int messageLength = messageContent.size();
		if(messageLength > 65535)
			throw std::runtime_error("Message TOO big");

		unsigned char msgSizeBits[2];
		msgSizeBits[1] = (unsigned char)(messageLength); // lowbit
		msgSizeBits[0] = (unsigned char)(messageLength >> 8); // highbit
		std::stringstream messageStream;
		std::string fullMessage;
		fullMessage.reserve(messageContent.size() +2);

		messageStream << msgSizeBits[0] <<msgSizeBits[1]<< messageContent;
		fullMessage = messageStream.str();


		MessageChunker chunker(2048,fullMessage);
		chunker.chunkMessage(messageChunks);

		this->sendMessageChunks(messageChunks);
	}
	delete data;
}

void TwoByteMsgLen::sendMessageChunks(std::list<std::string>& chunks)
{
	std::list<std::string>::iterator chunkIt;
	std::stringstream infoMessageStream;
	infoMessageStream << "TCP Trancever sending " << chunks.size() << " message chunks";
	ErrorLogger::logInfo(infoMessageStream.str());

	for(chunkIt = chunks.begin(); chunkIt != chunks.end(); chunkIt++)
	{
		std::string message = *chunkIt;
		this->socket.send(boost::asio::buffer(message.c_str(),message.length()));
	}
}

bool TwoByteMsgLen::isRequestNextDataMessage(AbstractMessage* msg)
{
	TranslatedMessages::RequestNextDataChunkMessage * reqNextChunk = dynamic_cast<TranslatedMessages::RequestNextDataChunkMessage*>(msg);
	return reqNextChunk != NULL;
}

