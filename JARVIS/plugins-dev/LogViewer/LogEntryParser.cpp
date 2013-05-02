#include "LogEntryParser.h"

#include <boost/filesystem.hpp>
#include<boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include "../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"


LogEntryParser::LogEntryParser()
{
}


LogEntryParser::~LogEntryParser(void)
{

}

bool LogEntryParser::setLogFileLocation(std::string logFile)
{
	this->fileLocation = "";

	if ( !boost::filesystem::exists(logFile) )
		return false;

	this->fileLocation = logFile;

	

	return true;
}

void LogEntryParser::openLogFile()
{
	this->logFile.open(this->fileLocation);
}
void LogEntryParser::closeLogFileIfOpen()
{
	if(this->logFile.is_open())
		this->logFile.close();
}

bool LogEntryParser::getAllEntrys(std::priority_queue<model::LogEntry>& list)
{
	openLogFile();

	std::string nextLogEntry;
	while(getNextLine(nextLogEntry))
		list.push(parseLogEntry(nextLogEntry));

	closeLogFileIfOpen();
	return true;
}


bool LogEntryParser::getNextLine(std::string& logEntry)
{
	if(this->logFile.is_open() && this->logFile.good())
	{
		char line[2048];
		this->logFile.getline(line,2048);
		
		logEntry.clear();
		logEntry += line;
		if(logEntry.size() == 0) return false;
		return true;
	}
	return false;
}

model::LogEntry LogEntryParser::parseLogEntry(std::string message)
{
	using namespace boost;

	tokenizer<escaped_list_separator<char>> tok(message);
	tokenizer<escaped_list_separator<char> >::iterator beg=tok.begin();
	std::string timeStamp, txtMessage, severityStr;
		
	if(beg == tok.end()) std::cerr <<"missing element 1 from Log file"; //ErrorLogger::logError("missing element 1 from Log file");
	timeStamp = *beg;
	beg++;

	if(beg == tok.end()) std::cerr <<"missing element 2 from Log file";//ErrorLogger::logError("missing element 2 from Log file");
	severityStr = *beg;
	beg++;

	if(beg == tok.end())std::cerr <<"missing element 3 from Log file"; //ErrorLogger::logError("missing element 3 from Log file");
	txtMessage = *beg;
	
	boost::algorithm::trim(timeStamp);
	boost::algorithm::trim(txtMessage);
	boost::algorithm::trim(severityStr);

	return model::LogEntry(timeStamp,txtMessage, parseEntrySeverity(severityStr));
}

model::LogEntry::SEVERITY LogEntryParser::parseEntrySeverity(std::string severityStr)
{
	if(severityStr.compare("ERR") == 0)
		return model::LogEntry::ERROR;
	if(severityStr.compare("INFO") == 0)
		return model::LogEntry::INFO;
	if(severityStr.compare("WARN") == 0)
		return model::LogEntry::WAR;

	return model::LogEntry::ERROR;
}
