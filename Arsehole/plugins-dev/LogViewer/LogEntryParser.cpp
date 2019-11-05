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

bool LogEntryParser::getParsedEntries(
	std::vector<model::LogEntry>& list,
	std::size_t n
) {
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
		this->logFile.seekg(-1,this->logFile.end);
		this->logFile.read(&c,1);
		for(int numEntrys = 0; numEntrys < n; numEntrys ++)
		{
			while(c != '\n' && (int)this->logFile.tellg() > 0)
			{
				offsetFromEnd++;
				this->logFile.seekg(-offsetFromEnd,this->logFile.end);
				this->logFile.read(&c,1);
			}
			c = 0;
		}
		char* last10Entrys = new char[offsetFromEnd];

		this->logFile.clear();
		this->logFile.seekg(-(offsetFromEnd-1), this->logFile.end);
		this->logFile.read(last10Entrys,offsetFromEnd-1);

		// my patients ran out w/e
		last10Entrys[offsetFromEnd-1] = '\0';
		last10Entrys[offsetFromEnd-2] = '\0';
		last10Entrys[offsetFromEnd-3] = '\0';

		std::string tmp10Entrys(last10Entrys);
		boost::split( logEntrys, tmp10Entrys, boost::is_any_of("\n"), boost::token_compress_off );

		delete[] last10Entrys;
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
