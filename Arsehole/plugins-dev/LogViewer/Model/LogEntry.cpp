/*
	Author : Craig Matear
*/
#include "LogEntry.h"
#include <sstream>


namespace model {



void LogEntry::parseTimeString(std::string timestamp)
{
	std::stringstream ss(timestamp);
	ss.imbue(this->timestampFormat);
	ss >> this->time;
}


LogEntry::LogEntry(std::string logTime, std::string timeFormat, std::string logMessage, SEVERITY severity):  timestampFormat(std::locale(std::locale::classic(),new boost::posix_time::time_input_facet(timeFormat)))
{
	parseTimeString(logTime);
	this->initalise(logMessage, severity);
}

LogEntry::LogEntry(std::string logTime, std::string logMessage, SEVERITY severity) :  timestampFormat(std::locale(std::locale::classic(),new boost::posix_time::time_input_facet("%Y-%m-%d %H:%M:%S")))
{
	parseTimeString(logTime);
	this->initalise(logMessage, severity);
	
}

LogEntry::LogEntry():  timestampFormat(std::locale(std::locale::classic(),new boost::posix_time::time_input_facet("%Y-%m-%d %H:%M:%S")))
{
	parseTimeString("0-0-0 0:0:0");
	this->initalise("Empty Entry",model::LogEntry::ERROR);
}

LogEntry::~LogEntry()
{
}

bool LogEntry::operator<(const LogEntry rhs) const
{
	if(this->time < rhs.time)
		return true;
	return false;
}

bool LogEntry::operator>(const LogEntry rhs) const
{
	if(this->time > rhs.time)
		return true;
	return false;
}

void LogEntry::initalise(std::string logMessage, SEVERITY severity)
{
	this->message = logMessage;
	this->severity = severity;
}


boost::posix_time::ptime LogEntry::logTimeStamp()
{
	return this->time;
}

LogEntry::SEVERITY LogEntry::getSeverity()
{
	return this->severity;
}


std::string LogEntry::getSeverityStr()
{
	switch(this->severity)
	{
		case LogEntry::ERROR:
			return "Error";
		case LogEntry::WAR:
			return "Warning";
		case LogEntry::INFO:
			return "info";
		default:
			return "unknown";
	}
}

std::string LogEntry::getMessage()
{
	return this->message;
}




}



