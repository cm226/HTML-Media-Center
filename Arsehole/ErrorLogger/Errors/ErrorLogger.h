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
#include "../../ArseholeCoreModules/CoreModules/config.h"

#define WRITE_TO_LOGFILE true
#define WRITE_TO_CONSOL true

#define LOG_STACK_TRACE_ERR false
#define LOG_STACK_TRACE_WARN false
#define LOG_STACK_TRACE_INFO false

#define LOG_ERR true
#define LOG_WARN true
#define LOG_INFO true


class ERROR_API ErrorLogger {

private:
	static void appendToLogFile(std::string message);

	static std::string buildFormatedErrEntry(std::string message);
	static std::string buildFormatedWarnEntry(std::string message);
	static std::string buildFormatedInfoEntry(std::string message);
	static std::string buildDateString();

	static void writeLogEntry(std::string entry);


public:
	ErrorLogger();

	static void logError(std::string message);
	static void logWarn(std::string message);
	static void logInfo(std::string message);

	virtual ~ErrorLogger();
};

#endif /* ERRORLOGGER_H_ */
