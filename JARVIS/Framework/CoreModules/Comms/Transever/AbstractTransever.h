/*
 * AbstractTransever.h
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#ifndef ABSTRACTTRANSEVER_H_
#define ABSTRACTTRANSEVER_H_

#include <string>
#include "../../Errors/ErrorLogger.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

class AbstractTransever {
public:
	AbstractTransever();
	virtual ~AbstractTransever();


	virtual int listenForConnection(int timeout) = 0;


	void error(std::string msg);
private:

};

#endif /* ABSTRACTTRANSEVER_H_ */
