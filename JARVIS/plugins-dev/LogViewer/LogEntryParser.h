#pragma once
#include <string>
#include <queue>
#include <iostream>
#include <fstream>


#include "Model\LogEntry.h"
class LogEntryParser
{
private:
	std::string fileLocation;
	std::ifstream logFile;

	bool readLast10Entrys(std::vector<std::string>& logEntrys);
	model::LogEntry parseLogEntry(std::string message);
	model::LogEntry::SEVERITY parseEntrySeverity(std::string severityStr);

	void openLogFile();
	void closeLogFileIfOpen();

public:
	LogEntryParser(void);
	~LogEntryParser(void);

	bool setLogFileLocation(std::string logFile);
	bool getAllEntrys(std::priority_queue<model::LogEntry>& list);
};

