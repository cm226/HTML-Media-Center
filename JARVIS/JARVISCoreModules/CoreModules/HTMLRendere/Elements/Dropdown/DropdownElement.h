#pragma once
#include "../../../exportMacros.h"

#include <string>

class DLLCORE_API DropdownElement
{

private:
	std::string _name;
	std::string _value;
	bool _selected;

public:
	DropdownElement();
	~DropdownElement();

	std::string Name();
	std::string Value();
	bool Selected();

	void Name(std::string&);
	void Value(std::string&);
	void Selected(bool);

};