#include "Dropdown.h"



Dropdown::Dropdown(std::string name) : IElement(name)
{
}


Dropdown::~Dropdown()
{
}

void Dropdown::AddItem(std::string name, std::string value, int depth, CALLBACk_HANDLE handl)
{
	std::pair<std::string, std::string> item(name, value);
	this->_elements.push_back(item);
}

std::string Dropdown::getTagText()
{
	return "select";
}

std::string Dropdown::getTagContent()
{
	std::list<std::pair<std::string, std::string>>::iterator items;
	std::stringstream str_builder; 

	for (items = this->_elements.begin();
		 items != this->_elements.end();
		 items++)
	{
		str_builder << "<option value=\"" << items->second << "\">" << items->first<< "</option>";
	}

	return str_builder.str();

}
