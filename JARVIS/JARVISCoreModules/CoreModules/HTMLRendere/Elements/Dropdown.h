#pragma once

#include "../IElement.h"
#include "../../exportMacros.h"

#include <string>
#include <list>

class DLLCORE_API Dropdown :
	public IElement
{
private:
	std::list<std::pair<std::string, std::string> > _elements;

	virtual std::string getTagText();
	virtual std::string getTagContent();

public:
	Dropdown(std::string name);
	~Dropdown();

	void AddItem(std::string name,std::string value, int depth, CALLBACk_HANDLE handl);
};

