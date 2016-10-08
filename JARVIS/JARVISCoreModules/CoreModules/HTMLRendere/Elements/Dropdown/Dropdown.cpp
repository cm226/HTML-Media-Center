#include "Dropdown.h"



Dropdown::Dropdown(std::string name) : IElement(name)
{
}


Dropdown::~Dropdown()
{
}

void Dropdown::AddItem(DropdownElement& element)
{
	this->_elements.push_back(element);
}

std::string Dropdown::getTagText()
{
	return "select";
}

std::string Dropdown::getTagContent()
{
	std::list<DropdownElement>::iterator items;
	std::stringstream str_builder; 

	for (items = this->_elements.begin();
		 items != this->_elements.end();
		 items++)
	{
		str_builder << "<option value=\"" << items->Value() << "\"";
		if (items->Selected())
			str_builder << " selected ";

		str_builder << ">" << items->Name() << "</option>";
	}

	return str_builder.str();

}
