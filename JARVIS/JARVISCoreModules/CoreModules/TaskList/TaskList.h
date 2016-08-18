#ifndef TASK_LIST_
#define TASK_LIST_

#include "../exportMacros.h"
#include <string>
#include <vector>

#include <boost/thread.hpp>


class DLLCORE_API TaskList {
private:
	bool _processTasks;
	bool _shutdownOnComplete;
	std::list<std::string> _tasks;
	boost::thread* _taskThread;

	void processTasks();


public:

	TaskList();
	virtual ~TaskList();

	void StartTasks();

	void AddTask(std::string cmd);
	std::list<std::string> GetTasks();

	void ShutdownOnComplete(bool shutdown);

};


#endif
