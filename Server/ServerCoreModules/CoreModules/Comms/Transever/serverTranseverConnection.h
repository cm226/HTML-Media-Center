/*
 * ServerTranseverConnection.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#ifndef ServerTRANSEVERCONNECTION_H_
#define ServerTRANSEVERCONNECTION_H_

#include "ITranseverConnection.h"

class ServerTranseverConnection: public ITranseverConnection
{


public:
	ServerTranseverConnection(boost::asio::io_service& service);
	virtual ~ServerTranseverConnection();

	virtual void processConnection();
};

#endif /* ServerTRANSEVERCONNECTION_H_ */
