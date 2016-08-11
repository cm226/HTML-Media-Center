#include "TaskList.h"

#include <stdio.h>
#include <string>
#include <boost/thread.hpp>
#include <stdlib.h>

#include "../../../ErrorLogger/Errors/ErrorLogger.h"
TaskList::TaskList()
{
	ErrorLogger::logInfo("Loading Task List...");
	this->_processTasks = false;
}

TaskList::~TaskList()
{
	ErrorLogger::logInfo("Stopping Task List...");
	this->_processTasks = false;
	this->_taskThread->join();

	delete this->_taskThread;

}

void TaskList::StartTasks()
{
	ErrorLogger::logInfo("Starting Task List...");

	if (system(NULL))
	{
		this->_processTasks = true;
		this->_taskThread = new boost::thread(boost::bind(&TaskList::processTasks, this));
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
		}

		boost::this_thread::sleep(boost::posix_time::milliseconds(100));
	}

}
/*
boost::process::child TaskList::startNextTask()
{

	std::vector<std::string> args;
	boost::process::context ctx;
	ctx.stdout_behavior = boost::process::capture_stream();

	if (this->_tasks.size() <= 0)
	{
		ErrorLogger::logError("startNextTask() called with empty tasklist");
		return boost::process::launch("", args, ctx);
	}

	std::string exec = this->_tasks.front();
	this->_tasks.pop_front();

	ErrorLogger::logInfo("Starting Task" + exec);
	return boost::process::launch(exec, args, ctx);
}
*/

void TaskList::AddTask(std::string cmd)
{
	std::cout << "adding command: " << cmd;
	this->_tasks.push_back(cmd);
}

std::list<std::string> TaskList::GetTasks()
{
	return this->_tasks;
}
