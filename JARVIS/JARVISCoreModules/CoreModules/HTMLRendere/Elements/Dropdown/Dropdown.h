#pragma once

#include "../../IElement.h"
#include "../../../exportMacros.h"

#include "DropdownElement.h"

#include <string>
#include <list>

class DLLCORE_API Dropdown :
	public IElement
{
private:
	std::list<DropdownElement> _elements;

	virtual std::string getTagText();
	virtual std::string getTagContent();

public:
	Dropdown(std::string name);
	~Dropdown();

	void AddItem(DropdownElement& element);
};

