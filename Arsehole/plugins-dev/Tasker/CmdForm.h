#pragma once

#include "../../arseholeCoreModules/CoreModules/HTMLRendere/HTMLRendere.h"

enum FILETYPE {BLENDER};

class CmdForm
{
private:
	Page* _page;

	bool _default_set;
	std::string _fileName;
	FILETYPE _filetype;

	void buildCommandPresets(Form* form);

public:
	CmdForm();
	~CmdForm();

	void SetDefaultFileName(FILETYPE filetype, std::string fileName);
	void Build(Page* page, CALLBACk_HANDLE submitCallback, std::string pluginName);
};

