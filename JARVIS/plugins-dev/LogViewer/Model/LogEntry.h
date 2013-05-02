/*
	Author : Craig Matear
*/
#pragma once
#ifndef MODEL_LOGENTRY_H
#define MODEL_LOGENTRY_H

#include "boost/date_time/posix_time/posix_time.hpp"
#include <string>

namespace model {


/**
	LogEntry
*/
class LogEntry
{


public:

	enum SEVERITY {INFO, WAR, ERROR};
	/**
		ctor
	*/
	LogEntry(std::string timestamp, std::string logMessage, SEVERITY severity);
	LogEntry(std::string timestamp, std::string timeFormat, std::string logMessage, SEVERITY severity);
	/**
		dtor
	*/
	~LogEntry();

	boost::posix_time::ptime logTimeStamp();
	SEVERITY getSeverity();
	std::string getSeverityStr();
	std::string getMessage();

	bool operator<(const LogEntry rhs) const;
	bool operator>(const LogEntry rhs) const;

private:
	boost::posix_time::ptime time;
	std::locale timestampFormat;
	std::string message;
	SEVERITY severity;

	void parseTimeString(std::string timestamp);

	void initalise(std::string message,SEVERITY severity);
};




}


#endif



