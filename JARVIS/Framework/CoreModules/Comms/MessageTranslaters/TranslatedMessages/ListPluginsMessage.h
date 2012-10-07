/*
 * ListPluginsMessage.h
 *
 *  Created on: Oct 3, 2012
 *      Author: craig
 */

#ifndef LISTPLUGINSMESSAGE_H_
#define LISTPLUGINSMESSAGE_H_

#include "AbstractMessage.h"

class ListPluginsMessage: public AbstractMessage {
public:
	ListPluginsMessage();
	virtual ~ListPluginsMessage();

	void actionMessage();
};

#endif /* LISTPLUGINSMESSAGE_H_ */
