#pragma once
#include <string>
#include <list>

#include "../../JARVISCoreModules/CoreModules/HTMLRendere/HTMLRendere.h"

struct AddTaskPageData
{
	std::list<std::string> _taskList;
	std::list<std::wstring> _pngFiles;
	std::list<std::wstring> _blendFiles;
	std::string _pluginName;
	CALLBACk_HANDLE _submitCallback;
	CALLBACk_HANDLE _fileUploadCallback;
};


class AddTaskPage
{
private:
	AddTaskPageData& _pageData;
	Page* _page;

	void wStringToString(std::wstring& in, std::string& out);
	void makeURLWeblink(std::wstring& location, bool& success);
	
	void buildCmdString();

	void buildForm();
	void buildOutputFileList();
	void buildBlendFileList();

public:
	AddTaskPage(AddTaskPageData& pageData);
	virtual ~AddTaskPage();

	void TaskList(std::list<std::string>& taskList);

	void Make(Page* p);
};

