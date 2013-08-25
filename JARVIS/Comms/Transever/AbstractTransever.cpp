/*
 * AbstractTransever.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#include "AbstractTransever.h"



AbstractTransever::AbstractTransever() {

}

AbstractTransever::~AbstractTransever() {
}

void AbstractTransever::error(std::string msg)
{
	ErrorLogger::logError(msg);
}
