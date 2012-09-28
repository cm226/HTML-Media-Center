/*
 * TCPTransever.h
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#ifndef TCPTRANSEVER_H_
#define TCPTRANSEVER_H_

#include "AbstractTransever.h"

class TCPTransever : AbstractTransever {
public:
	static const int PORT = 46000;

		int socketFd, newSocketFd, portNo;

	TCPTransever();
	virtual ~TCPTransever();

	virtual bool startComms(int port);
};

#endif /* TCPTRANSEVER_H_ */
