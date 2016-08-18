/*
 * ITranseverConnectionFactory.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#pragma once

#include "ITranseverConnection.h"


class ITranseverConnectionFactory
{
public:
	ITranseverConnectionFactory();
	virtual ~ITranseverConnectionFactory();

	virtual boost::shared_ptr<ITranseverConnection> create(boost::asio::io_service& service) = 0;
};

