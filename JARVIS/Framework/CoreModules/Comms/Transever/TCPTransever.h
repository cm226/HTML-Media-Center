/*
 * TCPTransever.h
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#ifndef TCPTRANSEVER_H_
#define TCPTRANSEVER_H_

#include "AbstractTransever.h"
#include <boost/asio.hpp>

class TCPTransever : public AbstractTransever {
public:
	static const int PORT = 46000;
	boost::asio::io_service io_service;


	TCPTransever();
	virtual ~TCPTransever();


	virtual int listenForConnection(int timeout);
};

#endif /* TCPTRANSEVER_H_ */
