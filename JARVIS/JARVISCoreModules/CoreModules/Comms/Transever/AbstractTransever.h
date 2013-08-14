/*
 * AbstractTransever.h
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#ifndef ABSTRACTTRANSEVER_H_
#define ABSTRACTTRANSEVER_H_

#include <string>
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "../MessageTranslaters/TranslatedMessages/AbstractMessage.h"

class AbstractTransever {
public:
	AbstractTransever();
	virtual ~AbstractTransever();


	virtual bool listenForConnection(int timeout) = 0;
	virtual AbstractMessage* getMessageOrTimeout(unsigned timoutMiliseconds) = 0;
	virtual void sendMessage(AbstractMessage* message) = 0;
	virtual void shutdown() = 0;
	void error(std::string msg);
private:

};

#endif /* ABSTRACTTRANSEVER_H_ */
