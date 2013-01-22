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
	std::cerr << message << std::endl;
}
