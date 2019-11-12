#ifndef TASK_LIST_
#define TASK_LIST_

#include "../exportMacros.h"
#include <string>
#include <vector>
#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>


class DLLCORE_API TaskList {

public:

	TaskList();
	virtual ~TaskList();

	void StartTasks();

	void AddTask(std::string cmd);
	std::list<std::string> GetTasks();

	void ShutdownOnComplete(bool shutdown);

	std::string RunSystemCommand(std::string cmd, bool& exit_code);

private:
	bool _processTasks;
	bool _shutdownOnComplete;
	std::list<std::string> _tasks;
	std::thread _taskThread;

	std::mutex m_mutex;
	std::condition_variable m_cv;

	void processTasks();


};


#endif
