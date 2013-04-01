/*
 * ErrorLogger.cpp
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#include "ErrorLogger.h"
#include <stdio.h>
#include <iostream>

#ifdef _WINDOWS
#include "MyStackWalker.h"
#endif

ErrorLogger::ErrorLogger() {

}

ErrorLogger::~ErrorLogger() {
}

void ErrorLogger::logError(std::string message)
{

	// TODO add date and time
	std::cerr <<"ERR: "<< message << std::endl;
	
	#ifdef _WINDOWS
	if(LOG_STACK_TRACE_ERR)
	{
		MyStackWalker msw;
		msw.ShowCallstack();
	}
	#endif
}

void ErrorLogger::logWarn(std::string message)
{
	std::cerr <<"WARN: "<< message << std::endl;

	#ifdef _WINDOWS
	if(LOG_STACK_TRACE_WARN)
	{
		MyStackWalker msw;
		msw.ShowCallstack();
	}
	#endif
}

void ErrorLogger::logInfo(std::string message)
{
	std::cerr <<"INFO: "<< message << std::endl;

	#ifdef _WINDOWS
	if(LOG_STACK_TRACE_INFO)
	{
		MyStackWalker msw;
		msw.ShowCallstack();
	}
	#endif
}
