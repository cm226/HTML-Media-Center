/*
 * ITranseverConnection.h
 *
 *  Created on: 20 May 2013
 *      Author: craig
 */

#ifndef ITRANSEVERCONNECTION_H_
#define ITRANSEVERCONNECTION_H_

#include <boost/asio.hpp>

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

#endif /* ITRANSEVERCONNECTION_H_ */
