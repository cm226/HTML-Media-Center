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

class AbstractTransever {
public:
	AbstractTransever();
	virtual ~AbstractTransever();


	virtual int listenForConnection(int timeout) = 0;
	virtual void getMessage(std::string* message) = 0;
	virtual void sendMessage(std::string* message) = 0;
	virtual void shutdown() = 0;
	void error(std::string msg);
private:

};

#endif /* ABSTRACTTRANSEVER_H_ */
