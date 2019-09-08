/*
 * ITranseverConnectionFactory.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#pragma once

#include "ITranseverConnection.h"

namespace MediaStreamingComms
{

class ITranseverConnectionFactory
{
public:
	ITranseverConnectionFactory();
	virtual ~ITranseverConnectionFactory();

	virtual boost::shared_ptr<MediaStreamingComms::ITranseverConnection> create(boost::asio::io_service& service) = 0;
};

}
