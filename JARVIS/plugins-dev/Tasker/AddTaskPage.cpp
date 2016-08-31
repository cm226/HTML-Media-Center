#include "AddTaskPage.h"

#include <boost/filesystem.hpp>

#include "../../JARVISCoreModules/CoreModules/config.h"

AddTaskPage::AddTaskPage(AddTaskPageData& pageData) : _pageData(pageData)
{
}


AddTaskPage::~AddTaskPage()
{
}


void AddTaskPage::wStringToString(std::wstring& in, std::string& out)
{
	// disaster waiting to happen :( fix TODO
	out = std::string(in.begin(), in.end());
}

void AddTaskPage::makeURLWeblink(std::wstring& location, bool& success)
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


void AddTaskPage::buildOutputFileList()
{
	std::list<std::wstring> outFileList;
	std::list<std::wstring>::iterator outFileListIt;

	Hyperlink* downloadLink;
	std::wstring w_URL_link;
	std::string URL_link;
	std::stringstream urlBuilder;

	bool webLinkMade = false;

	Lable* blendFile;

	outFileList = this->_pageData._pngFiles;
	
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
			this->_page->addElement(downloadLink);
			this->_page->addElement(new LineBreak("br"));
		}
	}
}

void AddTaskPage::buildCommandPresets(Form* form)
{
	std::stringstream blenderCommand;
	Dropdown* presetsDropdown = new Dropdown("presets");
	presetsDropdown->AddItem("", "", 0, 0);

	blenderCommand << "/opt/blender/blender -b ";
	blenderCommand << "file.blend ";
	blenderCommand << "-o " << HTMLMEDIAPUBLIC << TEMPLOC << "/frame_##### -f 1";
	presetsDropdown->AddItem("Blender", blenderCommand.str(), 0, 0);

	_page->addElement(presetsDropdown);

	Lable* lable = new Lable("Command");
	lable->setText("Set Command String:");

	TextBox* cmd_strTB = new TextBox("cmd_str");
	cmd_strTB->addAttribute("name=\"cmd_str\"");
	cmd_strTB->addAttribute("class=\"longTextBox\"");


	form->addElement(lable);
	form->addElement(cmd_strTB);
}

void AddTaskPage::buildBlendFileList()
{
	ElementList* blendFiles = new ElementList("blendFiles");
	std::list<std::wstring> blendFileList;
	std::list<std::wstring>::iterator blendFilesIt;
	Lable* blendFile;

	blendFileList = this->_pageData._blendFiles;

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

	this->_page->addElement(blendFiles);

}

void AddTaskPage::buildFormCmdString(Form* form)
{
	std::string cmd_str;
	Lable* commands = new Lable("cmd_list");
	std::list<std::string> tasks = this->_pageData._taskList;
	std::list<std::string>::iterator task_it;

	for (task_it = tasks.begin();
	task_it != tasks.end();
		task_it++)
	{
		cmd_str.append(*task_it);
		cmd_str.append("<br/>");
	}
	commands->setText(cmd_str);

	form->addElement(commands);
}

void AddTaskPage::buildForm()
{
	Form* form = new Form("Form");
	form->setHandler(1,
		this->_pageData._submitCallback,
		this->_pageData._pluginName);

	buildFormCmdString(form);
	this->buildCommandPresets(form);


	Lable* shutdownLable = new Lable("ShutdownLable");
	shutdownLable->setText("Shutdown on task complete: ");
	form->addElement(shutdownLable);

	Checkbox* shutdownOnComplete = new Checkbox("shutdownOnComplete");
	shutdownOnComplete->addAttribute("name=\"shutdown\"");
	form->addElement(shutdownOnComplete);
	
	FormSubmit* submitBttn = new FormSubmit("Submit");
	form->addElement(submitBttn);

	this->_page->addElement(form);

}

void AddTaskPage::Make(Page* page)
{

	this->_page = page;

	this->buildForm();
	this->buildBlendFileList();
	this->buildOutputFileList();


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

}
