/*
 * ErrorLogger.h
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#ifndef ERRORLOGGER_H_
#define ERRORLOGGER_H_

#include <string>
#include "../exportMacros.h"

#define LOG_STACK_TRACE_ERR false
#define LOG_STACK_TRACE_WARN false
#define LOG_STACK_TRACE_INFO false

class DLLCORE_API ErrorLogger {


public:
	ErrorLogger();

	static void logError(std::string message);
	static void logWarn(std::string message);
	static void logInfo(std::string message);

	virtual ~ErrorLogger();
};

#endif /* ERRORLOGGER_H_ */
