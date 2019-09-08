/*
 * ITranseverConnection.h
 *
 *  Created on: 20 May 2013
 *      Author: craig
 */

#pragma once

#include <boost/asio.hpp>

namespace MediaStreamingComms
{

class ITranseverConnection
{
public:

	ITranseverConnection(boost::asio::io_service& service);
	virtual ~ITranseverConnection();

	boost::asio::ip::tcp::socket& socket()
	  {
	    return socket_;
	  }
	virtual void processConnection()=0;

protected:
	boost::asio::ip::tcp::socket socket_;
};

}

