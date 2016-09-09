#include "TaskerPlugin.h"


#include <stdio.h>


#include "../../JARVISCoreModules/CoreModules/config.h"
#include "AddTaskPage.h"

#include "someRandClass.h"

TaskerPlugin::TaskerPlugin(CoreModules* framework) : Plugin(framework) , plugin_name("Tasker")
{
	boost::function2<bool, Page*, PageCallbackContext* > f = boost::bind(&TaskerPlugin::handleTaskAdded, this, _1, _2);
	this->taskAdded = this->subscribeHTMLCallback(f);

	someRandClass test;
}


TaskerPlugin::~TaskerPlugin()
{
}


bool TaskerPlugin::whatDoYouLookLike(Page* page)
{
	
	AddTaskPageData taskPageData;
	std::list<std::wstring> PNG_files, Blend_files;

	this->coreMod->getFileSystem().RetrieveNewFiles(".blend", Blend_files);
	this->coreMod->getFileSystem().RetrieveNewFiles(".png", PNG_files);

	taskPageData._taskList = this->coreMod->getTaskList().GetTasks();
	taskPageData._blendFiles = Blend_files;
	taskPageData._pngFiles = PNG_files;
	taskPageData._pluginName = this->plugin_name;
	taskPageData._submitCallback = this->taskAdded;

	AddTaskPage addTaskPage(taskPageData);
	addTaskPage.Make(page);
	
	return true;
}

const char* TaskerPlugin::pluginName()
{
	return this->plugin_name.c_str();
}

bool TaskerPlugin::handleTaskAdded(Page* page, PageCallbackContext* context)
{
	std::map<std::string, std::string> keyValContext = 
		context->getKeyValueAdditionalContext();

	if(keyValContext.find("cmd_str") != keyValContext.end())
		this->coreMod->getTaskList().AddTask(keyValContext["cmd_str"]);
	else
	{
		ErrorLogger::logError("failed to find cmd_str in add task page context");

	}

	if (keyValContext.find("shutdown") != keyValContext.end())
	{
		if (keyValContext["shutdown"].compare("on") == 0)
			this->coreMod->getTaskList().ShutdownOnComplete(true);
	}

	return true;
}

