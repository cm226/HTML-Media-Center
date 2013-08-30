/*
 * JARVISTranseverConnection.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#ifndef JARVISTRANSEVERCONNECTION_H_
#define JARVISTRANSEVERCONNECTION_H_

#include "../../../../Comms/Transever/ITranseverConnection.h"

class JARVISTranseverConnection: public ITranseverConnection
{


public:
	JARVISTranseverConnection(boost::asio::io_service& service);
	virtual ~JARVISTranseverConnection();

	virtual void processConnection();
};

#endif /* JARVISTRANSEVERCONNECTION_H_ */
