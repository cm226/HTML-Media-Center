/*
 * ErrorLogger.cpp
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#include "ErrorLogger.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/date_time/posix_time/posix_time.hpp>

#ifdef _WINDOWS
#include "MyStackWalker.h"
#endif

ErrorLogger::ErrorLogger() {

}

ErrorLogger::~ErrorLogger() {
}

void ErrorLogger::logError(std::string message)
{
	if(!LOG_ERR) return;
	
	std::string formatedLogentry = ErrorLogger::buildFormatedErrEntry(message);
	writeLogEntry(formatedLogentry);
	
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
	if(!LOG_WARN) return;
	std::string formatedLogentry = ErrorLogger::buildFormatedWarnEntry(message);
	writeLogEntry(formatedLogentry);

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
	if(!LOG_INFO) return;
	
	std::string formatedLogentry = ErrorLogger::buildFormatedInfoEntry(message);
	writeLogEntry(formatedLogentry);

	#ifdef _WINDOWS
	if(LOG_STACK_TRACE_INFO)
	{
		MyStackWalker msw;
		msw.ShowCallstack();
	}
	#endif
}

void ErrorLogger::writeLogEntry(std::string entry)
{
	if(WRITE_TO_LOGFILE) ErrorLogger::appendToLogFile(entry);
	if(WRITE_TO_CONSOL)	std::cerr <<entry;
}

void ErrorLogger::appendToLogFile(std::string message)
{
	using namespace std;
	ofstream logFile;
	logFile.open((LOG_LOCATION+std::string("\\log.log")).c_str(), fstream::out | fstream::app);
	if(logFile.is_open())
	{
		logFile << message;
		logFile.close();
	}

}


std::string ErrorLogger::buildFormatedErrEntry(std::string message)
{
	std::stringstream formatedMessage;
	formatedMessage << ErrorLogger::buildDateString() << ", "<<"ERR, "<<message << std::endl;
	return formatedMessage.str();
}

std::string ErrorLogger::buildFormatedWarnEntry(std::string message)
{
	std::stringstream formatedMessage;
	formatedMessage << ErrorLogger::buildDateString() << ", "<<"WARN, "<<message<< std::endl;
	return formatedMessage.str();
}

std::string ErrorLogger::buildFormatedInfoEntry(std::string message)
{
	std::stringstream formatedMessage;
	formatedMessage << ErrorLogger::buildDateString() << ", "<<"INFO, "<<message<< std::endl;
	return formatedMessage.str();
}

std::string ErrorLogger::buildDateString()
{
	boost::posix_time::ptime now(boost::posix_time::second_clock::local_time());

	std::stringstream formatedDateString;

	formatedDateString << ((int)now.date().year())<<"-"<<now.date().month()<<"-"<<now.date().day()<<" "<<now.time_of_day().hours() << ":" << now.time_of_day().minutes()<<":"<<now.time_of_day().seconds();
	return formatedDateString.str();
}


