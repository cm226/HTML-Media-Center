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

	virtual bool startComms(int port) = 0;

private:
	void error(std::string msg);
};

#endif /* ABSTRACTTRANSEVER_H_ */
