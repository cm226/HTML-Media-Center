/*
 * TCPTransever.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#include "TCPTransever.h"
#include <boost/bind.hpp>


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
}


int TCPTransever::listenForConnection(int timeout)
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

void TCPTransever::getMessage(std::string* message)
{
	boost::asio::socket_base::bytes_readable command(true);
	curSocket->io_control(command);

	int wateCounter = 0;
	std::size_t bytes_readable;
	while((bytes_readable = command.get()) == 0)
	{
		if(wateCounter > 5)
		{
			*message = "";
			ErrorLogger::logError("Connection Closed due to non responcive end point");
			if(this->curSocket->is_open())
				this->curSocket->shutdown(boost::asio::socket_base::shutdown_both);
			delete this->curSocket;
			return; // 
		}
#ifdef _WINDOWS
		Sleep(1000); // sleep for a second
#else
		sleep(1);
#endif

		wateCounter++;
	}

	char* msg = new char[bytes_readable+1];
	boost::system::error_code error;
	boost::asio::read(*curSocket,boost::asio::buffer(msg,bytes_readable),error);
	std::cout << error;
	msg[bytes_readable] = '\0';
	*message = std::string(msg);
}

void TCPTransever::sendMessage(std::string* data)
{
	if(this->curSocket->is_open())
	{
		this->curSocket->send(boost::asio::buffer(data->c_str(),data->length()));
	}
}

void TCPTransever::shutdown()
{
	this->stopped_ = true;
}

