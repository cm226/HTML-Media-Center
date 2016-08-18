#include "CheckBox.h"

Checkbox::Checkbox(std::string name) : IElement(name)
{
	this->addAttribute("type=\"checkbox\"");
}

Checkbox::~Checkbox()
{

}

std::string Checkbox::getTagText()
{
	return "input";
}

std::string Checkbox::getTagContent()
{
	return "";
}



