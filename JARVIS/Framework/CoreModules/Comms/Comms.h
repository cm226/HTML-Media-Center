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

class Comms {


public:
	Comms();
	virtual ~Comms();

	void startComms();


};

#endif /* COMMS_H_ */
