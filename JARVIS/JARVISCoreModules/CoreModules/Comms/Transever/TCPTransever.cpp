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
#include "../MessageTranslaters/StringMessageSerializer.h"


using boost::asio::ip::tcp;



TCPTransever::TCPTransever(int PORT)
{
	this->curSocket = NULL;
	this->timer = new boost::asio::deadline_timer(io_service);

	this->PORT = PORT;
	this->stopped_ = false;
}

TCPTransever::~TCPTransever()
{


	if(this->curSocket != NULL)
	{
		if(this->curSocket->is_open())
			this->curSocket->shutdown(boost::asio::socket_base::shutdown_both);

		delete this->curSocket;
	}


	this->timer->cancel();
	delete this->timer;
}


bool TCPTransever::listenForConnection(int timeout)
{

	tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), this->PORT));
	curSocket = new boost::asio::ip::tcp::socket(io_service);

	this->timer->expires_from_now(boost::posix_time::seconds(timeout));
	this->timer->async_wait(boost::bind(&TCPTransever::check_deadline, this));

	io_service.poll();

	try
	{
		acceptor.accept(*curSocket);
	}
	catch(boost::system::system_error& e)
	{
		if(this->stopped_)
			return false;

		throw boost::system::system_error(e); // preserve stack
	}

	return this->curSocket->is_open();
}


void TCPTransever::check_deadline()
 {
   if (this->stopped_)
     return;

   // Check whether the deadline has passed. We compare the deadline against
   // the current time since a new asynchronous operation may have moved the
   // deadline before this actor had a chance to run.
   if (this->timer->expires_at() <= boost::asio::deadline_timer::traits_type::now())
   {
     // The deadline has passed. The socket is closed so that any outstanding
     // asynchronous operations are cancelled.
     this->curSocket->close();

     // There is no longer an active deadline. The expiry is set to positive
     // infinity so that the actor takes no action until a new deadline is set.
     this->timer->expires_at(boost::posix_time::pos_infin);
   }

   // Put the actor back to sleep.
   this->timer->async_wait(boost::bind(&TCPTransever::check_deadline, this));
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

	AbstractMessage* message =  this->messageTranslater.translateMessage(accualMessage,messageSize+1);
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
		chunker.chunkMessage(messageChunks);

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
}

