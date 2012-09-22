/*
 * ErrorLogger.h
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#ifndef ERRORLOGGER_H_
#define ERRORLOGGER_H_

#include <string>

class ErrorLogger {
public:
	ErrorLogger();

	static void logError(std::string message);

	virtual ~ErrorLogger();
};

#endif /* ERRORLOGGER_H_ */
