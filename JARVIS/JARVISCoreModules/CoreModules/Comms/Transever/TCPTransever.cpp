/*
 * TCPTransever.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#include "TCPTransever.h"
#include <boost/bind.hpp>
#include "MessageChunker.h"
#include <boost/thread/thread.hpp>
#include <sstream>
#include <boost/date_time/posix_time/ptime.hpp>

#include "../MessageTranslaters/StringMessageSerializer.h"


using boost::asio::ip::tcp;



TCPTransever::TCPTransever(int PORT)
{
	this->curSocket =NULL;

	this->PORT = PORT;
	this->stopped_ = false;
	this->io_service.run();

}

TCPTransever::~TCPTransever()
{
	if(this->curSocket != NULL)
	{
		if(this->curSocket->is_open())
			this->curSocket->shutdown(boost::asio::socket_base::shutdown_both);

		delete this->curSocket;
	}
}


bool TCPTransever::listenForConnection(int timeout)
{
	if(this->curSocket != NULL)
	{
		if(this->curSocket->is_open())
					this->curSocket->shutdown(boost::asio::socket_base::shutdown_both);

		delete this->curSocket;
	}
	tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), this->PORT));
		acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));


	curSocket = new boost::asio::ip::tcp::socket(io_service);
	this->connectionMutex.lock();
	boost::system_time timeoutBoost = boost::get_system_time() +
	                             boost::posix_time::seconds(timeout);

	acceptor.async_accept((*curSocket), boost::bind(&TCPTransever::acceptConnection, this));
	bool gotLock = this->connectionMutex.timed_lock(timeoutBoost);
	this->connectionMutex.unlock();


	if(gotLock)
		return this->curSocket->is_open();
	else
		return false;
}

void TCPTransever::acceptConnection()
{
	this->connectionMutex.unlock();
}

AbstractMessage* TCPTransever::getMessageOrTimeout(unsigned timoutMiliseconds)
{
	boost::asio::socket_base::bytes_readable command(true);
	curSocket->io_control(command);

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
		curSocket->io_control(command);
		wateCounter++;
	}
	
	unsigned char* msgSize = new unsigned char[2];
	boost::system::error_code error;
	boost::asio::read(*curSocket,boost::asio::buffer(msgSize,2),error);

	int messageSize = msgSize[0];
	messageSize = messageSize << 8;
	messageSize += msgSize[1];

	std::cout << error;
	char* accualMessage = new char[messageSize+1];
	boost::asio::read(*curSocket,boost::asio::buffer(accualMessage,messageSize),error);
	accualMessage[messageSize] = '\0';

	AbstractMessage* message =  this->messageTranslater.translateMessage(accualMessage,messageSize);
	delete[] msgSize;
	return message;
}

void TCPTransever::sendMessage( AbstractMessage* data)
{
	if(this->curSocket->is_open())
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
		chunker.Chunk_Message(messageChunks);

		this->sendMessageChunks(messageChunks);
	}
}

void TCPTransever::sendMessageChunks(std::list<std::string>& chunks)
{
	std::list<std::string>::iterator chunkIt;
	std::stringstream infoMessageStream;
	infoMessageStream << "TCP Trancever sending " << chunks.size() << " message chunks";
	ErrorLogger::logInfo(infoMessageStream.str());

	for(chunkIt = chunks.begin(); chunkIt != chunks.end(); chunkIt++)
	{
		std::string message = *chunkIt;
		this->curSocket->send(boost::asio::buffer(message.c_str(),message.length()));
	}
}

bool TCPTransever::isRequestNextDataMessage(AbstractMessage* msg)
{
	TranslatedMessages::RequestNextDataChunkMessage * reqNextChunk = dynamic_cast<TranslatedMessages::RequestNextDataChunkMessage*>(msg);
	return reqNextChunk != NULL;
}

void TCPTransever::shutdown()
{
	this->stopped_ = true;
	this->io_service.stop();
}

