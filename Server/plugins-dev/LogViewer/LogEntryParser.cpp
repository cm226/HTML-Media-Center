#include "LogEntryParser.h"

#include <boost/filesystem.hpp>
#include<boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include "../../ErrorLogger/Errors/ErrorLogger.h"


LogEntryParser::LogEntryParser()
{
}


LogEntryParser::~LogEntryParser(void)
{

}

bool LogEntryParser::setLogFileLocation(std::string logFile)
{
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

bool LogEntryParser::getParsedEntries(
	std::vector<model::LogEntry>& list,
	std::size_t n
) {
	if ( !boost::filesystem::exists(this->fileLocation) )
		return false;

	openLogFile();

	std::vector<std::string> lastNLogEntrys;
	readLastNEntrys(lastNLogEntrys, n);

	for(auto& entry : lastNLogEntrys)
		list.push_back(parseLogEntry(entry));

	closeLogFileIfOpen();
	return true;
}


bool LogEntryParser::readLastNEntrys(std::vector<std::string>& logEntrys, unsigned int n)
{
	int offsetFromEnd = 0;
	char c;

	if(this->logFile.is_open() && this->logFile.good())
	{
		char c;
		this->logFile.seekg(0, std::ios::end);
		std::streampos size = this->logFile.tellg();
		std::vector<char> buffer;
		std::size_t lineCounter = 0;
		for(int i=2;i<=size;i++){ // start at 2, because the last character is always newline and we read forwards(kinda ugly but im feeling lazy)
			this->logFile.seekg(-i,std::ios::end);
			this->logFile.get(c);
			if(c=='\n'){
				lineCounter++;
				logEntrys.push_back(std::string(buffer.rbegin(), buffer.rend()));
				buffer.clear();
				continue;
			}
			if(lineCounter == n) break;
			buffer.push_back(c);
		}

		return true;
		
	}
	return false;
}

model::LogEntry LogEntryParser::parseLogEntry(std::string message)
{
	using namespace boost;


	escaped_list_separator<char> seps('%',',','\"');
	tokenizer<escaped_list_separator<char> > tok(message,seps);
	tokenizer<escaped_list_separator<char> >::iterator beg=tok.begin();
	std::string timeStamp, txtMessage, severityStr;
		
	if(beg == tok.end())
	{
			std::cerr <<"missing element 1 from Log file"; //ErrorLogger::logError("missing element 1 from Log file");
			return model::LogEntry();
	}
	timeStamp = *beg;
	beg++;

	if(beg == tok.end())
	{
		std::cerr <<"missing element 2 from Log file";//ErrorLogger::logError("missing element 2 from Log file");
		return model::LogEntry();
	}
	severityStr = *beg;
	beg++;

	if(beg == tok.end())
	{
		std::cerr <<"missing element 3 from Log file"; //ErrorLogger::logError("missing element 3 from Log file");
		return model::LogEntry();
	}
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
