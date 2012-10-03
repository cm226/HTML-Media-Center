/*
 * Translater.h
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#ifndef TRANSLATER_H_
#define TRANSLATER_H_

#include "TranslatedMessages/AbstractMessage.h"

class Translater {
public:
	Translater();
	virtual ~Translater();

	AbstractMessage* translateMessage(char* message, unsigned int messagelength);
};

#endif /* TRANSLATER_H_ */
