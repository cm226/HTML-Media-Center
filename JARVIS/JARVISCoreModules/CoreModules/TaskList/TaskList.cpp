#include "TaskList.h"

#include <stdio.h>
#include <string>
#include <thread>
#include <stdlib.h>
#include <iostream>
#include <chrono>

#include "../../../ErrorLogger/Errors/ErrorLogger.h"
TaskList::TaskList()
{
	ErrorLogger::logInfo("Loading Task List...");
	this->_processTasks = false;
	this->_shutdownOnComplete = false;
}

TaskList::~TaskList()
{
	ErrorLogger::logInfo("Stopping Task List...");
	this->_processTasks = false;
	this->_taskThread.join();
}

void TaskList::StartTasks()
{
	ErrorLogger::logInfo("Starting Task List...");

	if (system(NULL))
	{
		this->_processTasks = true;
		this->_taskThread = std::thread(&TaskList::processTasks, this);
	}
	else
	{
		ErrorLogger::logError("Task list failed to aquire command processor");
	}
	
}

void TaskList::processTasks()
{
	while (this->_processTasks)
	{
		if (this->_tasks.size() > 0)
		{
			std::string exec = this->_tasks.front();
			this->_tasks.pop_front();

			ErrorLogger::logInfo("Starting Task" + exec);

			system(exec.c_str());

			ErrorLogger::logInfo("Task Finished" + exec);
			
			if (this->_shutdownOnComplete &&
				this->_tasks.size() == 0)
			{
				if (LIVE)
				{
					//all tasks complete, shutdown
#ifdef _WINDOWS
					system("shutdown -s -t 10");
#else
					system("shutdown -P 1");
#endif // _WINDOWS
				}
				else
				{
					ErrorLogger::logInfo("I would be shutting down now");
				}

			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

}

void TaskList::AddTask(std::string cmd)
{
	std::cout << "adding command: " << cmd;
	this->_tasks.push_back(cmd);
}

std::list<std::string> TaskList::GetTasks()
{
	return this->_tasks;
}


void TaskList::ShutdownOnComplete(bool shutdown)
{
	this->_shutdownOnComplete = shutdown;
}


std::string TaskList::RunSystemCommand(std::string cmd, bool& exit_code) {
	
	std::array<char, 2048> buffer;
    std::string result;
	FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        ErrorLogger::logError("Popen Failed!!");
		return "";
    }
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }

	auto exit = pclose(pipe);
	exit_code = WIFEXITED(exit);
	
    return result;

}