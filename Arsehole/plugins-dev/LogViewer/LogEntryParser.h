#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


#include "Model/LogEntry.h"
class LogEntryParser
{
private:
	std::string fileLocation;
	std::ifstream logFile;

	bool readLastNEntrys(std::vector<std::string>& logEntrys, unsigned int n);
	model::LogEntry parseLogEntry(std::string message);
	model::LogEntry::SEVERITY parseEntrySeverity(std::string severityStr);

	void openLogFile();
	void closeLogFileIfOpen();

public:
	LogEntryParser(void);
	~LogEntryParser(void);

	bool setLogFileLocation(std::string logFile);
	bool getParsedEntries(std::vector<model::LogEntry>& list, std::size_t n = 50);
};

