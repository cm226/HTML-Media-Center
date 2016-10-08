#include "DropdownElement.h"


DropdownElement::DropdownElement()
{

}


DropdownElement::~DropdownElement()
{

}


std::string DropdownElement::Name()
{
	return this->_name;
}

std::string DropdownElement::Value()
{
	return this->_value;

}

bool DropdownElement::Selected()
{
	return this->_selected;
}


void DropdownElement::Name(std::string& name)
{
	this->_name = name;
}

void DropdownElement::Value(std::string& value)
{
	this->_value = value;
}

void DropdownElement::Selected(bool selected)
{
	this->_selected = selected;
}