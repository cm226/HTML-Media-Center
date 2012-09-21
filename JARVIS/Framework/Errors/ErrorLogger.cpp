/*
 * ErrorLogger.cpp
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#include "ErrorLogger.h"
#include <stdio.h>

ErrorLogger::ErrorLogger() {
	// TODO Auto-generated constructor stub

}

ErrorLogger::~ErrorLogger() {
	// TODO Auto-generated destructor stub
}

void ErrorLogger::logError(std::string message)
{
	printf(message.c_str());
}
