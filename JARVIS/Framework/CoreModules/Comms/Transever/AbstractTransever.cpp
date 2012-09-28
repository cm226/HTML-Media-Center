/*
 * AbstractTransever.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#include "AbstractTransever.h"



AbstractTransever::AbstractTransever() {
	// TODO Auto-generated constructor stub

}

AbstractTransever::~AbstractTransever() {
	// TODO Auto-generated destructor stub
}

void AbstractTransever::error(std::string msg)
{
	//perror(msg.c_str());
	ErrorLogger::logError(msg);
}
