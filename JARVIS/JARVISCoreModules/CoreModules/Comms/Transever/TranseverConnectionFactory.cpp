/*
 * TranseverConnectionFactory.cpp
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#include "TranseverConnectionFactory.h"
#include "JARVISTranseverConnection.h"

TranseverConnectionFactory::TranseverConnectionFactory() {


}

TranseverConnectionFactory::~TranseverConnectionFactory() {

}

boost::shared_ptr<ITranseverConnection> TranseverConnectionFactory::create(boost::asio::io_service& service)
{
	return boost::shared_ptr<ITranseverConnection>(new JARVISTranseverConnection(service));
}

