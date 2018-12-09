/*
 * ITranseverConnection.cpp
 *
 *  Created on: 20 May 2013
 *      Author: craig
 */

#include "ITranseverConnection.h"

namespace MediaStreamingComms
{

ITranseverConnection::ITranseverConnection(boost::asio::io_service& service)
: socket_(service)
{
}

ITranseverConnection::~ITranseverConnection() {
	// TODO Auto-generated destructor stub
}

}
