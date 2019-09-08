/*
 * arseholeTranseverConnection.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#ifndef arseholeTRANSEVERCONNECTION_H_
#define arseholeTRANSEVERCONNECTION_H_

#include "ITranseverConnection.h"

class arseholeTranseverConnection: public ITranseverConnection
{


public:
	arseholeTranseverConnection(boost::asio::io_service& service);
	virtual ~arseholeTranseverConnection();

	virtual void processConnection();
};

#endif /* arseholeTRANSEVERCONNECTION_H_ */
