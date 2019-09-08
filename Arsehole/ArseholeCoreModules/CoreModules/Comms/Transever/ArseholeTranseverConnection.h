/*
 * ArseholeTranseverConnection.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#ifndef ArseholeTRANSEVERCONNECTION_H_
#define ArseholeTRANSEVERCONNECTION_H_

#include "ITranseverConnection.h"

class ArseholeTranseverConnection: public ITranseverConnection
{


public:
	ArseholeTranseverConnection(boost::asio::io_service& service);
	virtual ~ArseholeTranseverConnection();

	virtual void processConnection();
};

#endif /* ArseholeTRANSEVERCONNECTION_H_ */
