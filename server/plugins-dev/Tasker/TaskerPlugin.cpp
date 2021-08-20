#include "TaskerPlugin.h"


#include <stdio.h>


#include "../../ServerCoreModules/CoreModules/config.h"
#include "../../ServerCoreModules/CoreModules/Files/Files.h"
#include "AddTaskPage.h"
#include "CmdForm.h"

#include "someRandClass.h"

TaskerPlugin::TaskerPlugin(CoreModules* framework) : Plugin(framework) , plugin_name("Tasker")
{
	boost::function2<bool, Page*, PageCallbackContext* > taskAdded = boost::bind(&TaskerPlugin::handleTaskAdded, this, _1, _2);
	boost::function2<bool, Page*, PageCallbackContext* > fileUploaded = boost::bind(&TaskerPlugin::handleFileUploaded, this, _1, _2);

	this->taskAdded = this->subscribeHTMLCallback(taskAdded);
	this->fileUploaded = this->subscribeHTMLCallback(fileUploaded);
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
	taskPageData._fileUploadCallback = this->fileUploaded;

	AddTaskPage addTaskPage(taskPageData);
	addTaskPage.Make(page);
	
	return true;
}

const char* TaskerPlugin::pluginName()
{
	return this->plugin_name.c_str();
}

bool TaskerPlugin::handleFileUploaded(Page* page, PageCallbackContext* context)
{

	std::map<std::string, std::string> keyValContext =
		context->getKeyValueAdditionalContext();

	std::string filename;
	std::string base64Data;

	if (keyValContext.find("name") != keyValContext.end() &&
		keyValContext.find("value") != keyValContext.end())
	{
		filename = keyValContext.find("name")->second;
		base64Data = keyValContext.find("value")->second;
		base64Data = base64Data.substr(base64Data.find(',') + 1, std::string::npos);

		File uploadedFile(std::make_shared<Base64FileDataURLSource>(base64Data));
		uploadedFile.SetLocation(Directory(WORKING_FILES), filename);

		if (!uploadedFile.Save())
			ErrorLogger::logError("Failed write uploaded tasker file");
		else
		{
			CmdForm formBuilder;
			formBuilder.SetDefaultFileName(
				FILETYPE::BLENDER,
				uploadedFile.Location());
			
			formBuilder.Build(page,
				this->taskAdded,
				this->plugin_name);
		}
	}
	else
	{
		ErrorLogger::logError("failed to find uploaded image data in request");
	}


	return true;

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

