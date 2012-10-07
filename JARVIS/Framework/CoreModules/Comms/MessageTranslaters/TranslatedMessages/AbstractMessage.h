/*
 * AbstractMessage.h
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#ifndef ABSTRACTMESSAGE_H_
#define ABSTRACTMESSAGE_H_

class AbstractMessage {
public:
	AbstractMessage();
	virtual ~AbstractMessage();

	virtual void actionMessage() = 0;
};

#endif /* ABSTRACTMESSAGE_H_ */
