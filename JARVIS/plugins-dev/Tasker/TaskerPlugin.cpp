#include "TaskerPlugin.h"


#include <stdio.h>
#include <boost/filesystem.hpp>

#include "../../JARVISCoreModules/CoreModules/config.h"


TaskerPlugin::TaskerPlugin(CoreModules* framework) : Plugin(framework) , plugin_name("Tasker")
{
	boost::function2<bool, Page*, PageCallbackContext* > f = boost::bind(&TaskerPlugin::handleTaskAdded, this, _1, _2);
	this->taskAdded = this->subscribeHTMLCallback(f);
}


TaskerPlugin::~TaskerPlugin()
{
}

void TaskerPlugin::wStringToString(std::wstring& in, std::string& out)
{
	// disaster waiting to happen :( fix TODO
	out = std::string(in.begin(), in.end());
}

void TaskerPlugin::makeURLWeblink(std::wstring& location, bool& success)
{
	boost::filesystem::path fileLocation(location);
	boost::filesystem::path publicLocation(HTMLMEDIAPUBLIC);
	
	boost::filesystem::path::iterator webRoot_iter;
	boost::filesystem::path::iterator location_iter
		= fileLocation.begin();

	for (webRoot_iter = publicLocation.begin();
	webRoot_iter != publicLocation.end();
		webRoot_iter++)
	{
		if (webRoot_iter->compare(*location_iter) != 0)
		{
			success = false;
			return;
		}
		location_iter++;
	}

	success = true;
	boost::filesystem::path output;
	for (location_iter; location_iter != fileLocation.end(); location_iter++)
		output.append(location_iter->c_str());

	location = output.generic_wstring();
	return;
}

void TaskerPlugin::buildOutputFileList(Page* p)
{
	std::list<std::wstring> outFileList;
	std::list<std::wstring>::iterator outFileListIt;
	
	Hyperlink* downloadLink;
	std::wstring w_URL_link;
	std::string URL_link;
	std::stringstream urlBuilder; 

	bool webLinkMade = false;

	Lable* blendFile;

	this->coreMod->getFileSystem().RetrieveNewFiles(".png", outFileList);

	
	for (outFileListIt = outFileList.begin();
	outFileListIt != outFileList.end();
		outFileListIt++)
	{
		w_URL_link = *outFileListIt;
		makeURLWeblink(w_URL_link, webLinkMade);
		if (webLinkMade)
		{
			urlBuilder << "http:////" << HOST << "//HTML-Media-Center//public//";
			this->wStringToString(w_URL_link, URL_link);
			urlBuilder << URL_link;
			URL_link = urlBuilder.str();
			urlBuilder.str("");

			downloadLink = new Hyperlink(URL_link, URL_link, URL_link);
			p->addElement(downloadLink);
			p->addElement(new LineBreak("br"));
		}
	}
}

void TaskerPlugin::buildCommandPresets(Page* page, Form* form)
{
	Dropdown* presetsDropdown = new Dropdown("presets");
	presetsDropdown->AddItem("","", 0, 0);
	presetsDropdown->AddItem("Blender","blender -b file.blend -o /project/renders/frame_##### -f 1", 0, 0);

	page->addElement(presetsDropdown);

	Lable* lable = new Lable("Command");
	lable->setText("Set Command String:");

	TextBox* cmd_strTB = new TextBox("cmd_str");
	cmd_strTB->addAttribute("name=\"cmd_str\"");
	cmd_strTB->addAttribute("class=\"longTextBox\"");


	form->addElement(lable);
	form->addElement(cmd_strTB);
}

void TaskerPlugin::buildBlendFileList(Page* p)
{
	ElementList* blendFiles = new ElementList("blendFiles");
	std::list<std::wstring> blendFileList;
	std::list<std::wstring>::iterator blendFilesIt;
	Lable* blendFile;

	this->coreMod->getFileSystem().RetrieveNewFiles(".blend", blendFileList);

	for (blendFilesIt = blendFileList.begin();
		 blendFilesIt != blendFileList.end();
	   ++blendFilesIt)
	{
		std::string conv_str;
		this->wStringToString(*blendFilesIt, conv_str);

		blendFile = new Lable(conv_str);
		blendFile->setText(conv_str);
		blendFiles->addElement(blendFile);
	}

	p->addElement(blendFiles);

}

bool TaskerPlugin::whatDoYouLookLike(Page* page)
{

	Form* form = new Form("Form");
	std::list<std::string> tasks = this->coreMod->getTaskList().GetTasks();
	std::list<std::string>::iterator task_it;
	std::string cmd_str;

	Lable* commands = new Lable("cmd_list");
	Lable* shutdownLable = new Lable("ShutdownLable");
	Checkbox* shutdownOnComplete = new Checkbox("shutdownOnComplete");
	
	shutdownOnComplete->addAttribute("name=\"shutdown\"");

	for (task_it = tasks.begin();
		task_it != tasks.end();
		task_it++)
	{
		cmd_str.append(*task_it);
		cmd_str.append("<br/>");
	}
	commands->setText(cmd_str);
	shutdownLable->setText("Shutdown on task complete: ");

	this->buildCommandPresets(page, form);
	
	FormSubmit* submitBttn = new FormSubmit("Submit");

	form->setHandler(1, taskAdded, this->plugin_name);


	form->addElement(commands);
	form->addElement(submitBttn);
	form->addElement(shutdownLable);
	form->addElement(shutdownOnComplete);

	page->addElement(form);

	this->buildBlendFileList(page);
	this->buildOutputFileList(page);


	Lable* test = new Lable("test");
	std::stringstream dropdownJS;
	dropdownJS << std::endl << "$('#presets').change(" << std::endl
		<< "function() {"
		<< "$('#cmd_str').val($('#presets').val())"
		<< std::endl
		<< "})"
		<< std::endl;
	test->appendEmbeddedJSCode(dropdownJS.str());

	page->addElement(test);

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

