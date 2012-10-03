/*
 * Comms.h
 *
 *  Created on: Sep 26, 2012
 *      Author: craig
 */

#ifndef COMMS_H_
#define COMMS_H_

#include <string>
#include "../Errors/ErrorLogger.h"

#include "Transever/AbstractTransever.h"


class Comms {
private:
	AbstractTransever* transever;
	bool listening;
	void connectionListener();

public:
	int PORT;

	Comms();
	virtual ~Comms();

	void startComms();
	void stopComms();


};

#endif /* COMMS_H_ */
