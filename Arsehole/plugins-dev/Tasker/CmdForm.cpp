#include "CmdForm.h"

#include "../../arseholeCoreModules/CoreModules/config.h"

CmdForm::CmdForm() :_default_set(false)
{
}


CmdForm::~CmdForm()
{
}

void CmdForm::SetDefaultFileName(FILETYPE filetype, std::string fileName)
{
	this->_fileName = fileName;
	this->_filetype = filetype;
	this->_default_set = true;
}

void CmdForm::buildCommandPresets(Form* form)
{
	std::stringstream blenderCommand;
	Dropdown* presetsDropdown = new Dropdown("presets");
	presetsDropdown->AddItem(DropdownElement());

	blenderCommand << "/opt/blender/blender -b ";
	if(_default_set)
		blenderCommand << _fileName << " ";
	else
		blenderCommand << "file.blend ";

	blenderCommand << "-o " << HTMLMEDIAPUBLIC << TEMPLOC << "/frame_##### -f 1";

	DropdownElement blenderDropdownElement;
	blenderDropdownElement.Name(std::string("Blender"));
	blenderDropdownElement.Value(blenderCommand.str());

	if (_default_set && _filetype == FILETYPE::BLENDER)
		blenderDropdownElement.Selected(true);

	presetsDropdown->AddItem(blenderDropdownElement);

	_page->addElement(presetsDropdown);

	Lable* lable = new Lable("Command");
	lable->setText("Set Command String:");

	TextBox* cmd_strTB = new TextBox("cmd_str");
	cmd_strTB->addAttribute("name=\"cmd_str\"");
	cmd_strTB->addAttribute("class=\"longTextBox\"");


	std::stringstream dropdownJS;
	dropdownJS << std::endl << "$('#presets').change(" << std::endl
		<< "function() {"
		<< "$('#cmd_str').val($('#presets').val())"
		<< std::endl
		<< "})"
		<< std::endl;
	presetsDropdown->appendEmbeddedJSCode(dropdownJS.str());

	form->addElement(lable);
	form->addElement(cmd_strTB);
}

void CmdForm::Build(Page* page, CALLBACk_HANDLE submitCallback, std::string pluginName)
{
	this->_page = page;

	Form* form = new Form("Form");
	form->setHandler(
		submitCallback,
		pluginName);

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
