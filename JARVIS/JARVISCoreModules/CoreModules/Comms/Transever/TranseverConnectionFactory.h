/*
 * TranseverConnectionFactory.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#ifndef TRANSEVERCONNECTIONFACTORY_H_
#define TRANSEVERCONNECTIONFACTORY_H_

#include "ITranseverConnection.h"
#include "ITranseverConnectionFactory.h"
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

class TranseverConnectionFactory : public ITranseverConnectionFactory
{
public:
	TranseverConnectionFactory();
	virtual ~TranseverConnectionFactory();

	boost::shared_ptr<ITranseverConnection> create(boost::asio::io_service& service);
};

#endif /* TRANSEVERCONNECTIONFACTORY_H_ */
