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

}

ErrorLogger::~ErrorLogger() {
}

void ErrorLogger::logError(std::string message)
{
	// TODO add stacktrace to message 
	// TODO add date and time
	std::cerr << message << std::endl;
}
