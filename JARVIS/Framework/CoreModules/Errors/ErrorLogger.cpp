/*
 * ErrorLogger.cpp
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#include "ErrorLogger.h"
#include <stdio.h>
#include <iostream>

ErrorLogger::ErrorLogger() {
	// TODO Auto-generated constructor stub

}

ErrorLogger::~ErrorLogger() {
	// TODO Auto-generated destructor stub
}

void ErrorLogger::logError(std::string message)
{
	std::cerr << message << std::endl;
	//printf(message.c_str());
}
