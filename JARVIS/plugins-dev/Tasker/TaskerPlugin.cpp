#include "TaskerPlugin.h"

#include <stdio.h>


TaskerPlugin::TaskerPlugin(CoreModules* framework) : Plugin(framework) , plugin_name("Tasker")
{
	boost::function2<bool, Page*, PageCallbackContext* > f = boost::bind(&TaskerPlugin::handleTaskAdded, this, _1, _2);
	this->taskAdded = this->subscribeHTMLCallback(f);
}


TaskerPlugin::~TaskerPlugin()
{
}

bool TaskerPlugin::whatDoYouLookLike(Page* page)
{

	Form* form = new Form("Form");
	std::list<std::string> tasks = this->coreMod->getTaskList().GetTasks();
	std::list<std::string>::iterator task_it;
	std::string cmd_str;

	Lable* commands = new Lable("cmd_list");
	

	for (task_it = tasks.begin();
		task_it != tasks.end();
		task_it++)
	{
		cmd_str.append(*task_it);
		cmd_str.append("<br/>");
	}
	commands->setText(cmd_str);

	Lable* lable = new Lable ("Command");
	lable->setText("Set Command String:");

	TextBox* emailAddres = new TextBox("cmd_str");
	emailAddres->addAttribute("name=\"cmd_str\"");

	FormSubmit* submitBttn = new FormSubmit("Submit");

	form->setHandler(1, taskAdded, this->plugin_name);


	form->addElement(commands);
	form->addElement(lable);
	form->addElement(emailAddres);
	form->addElement(submitBttn);

	page->addElement(form);

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

	return true;
}

