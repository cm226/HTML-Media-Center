/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_HTMLRENDERE_ELEMENTS_MENULIST_MENULIST_H
#define COREMODULES_HTMLRENDERE_ELEMENTS_MENULIST_MENULIST_H

#include "../../IElement.h"
#include "../../Containers/ElementList.h"
#include "../../../exportMacros.h"
#include <string>

namespace coremodules {
namespace htmlrendere {
namespace elements {
namespace menulist {


/**
	MenuList
*/
class DLLCORE_API MenuList : public IElement
{
protected:

	std::string getTagText();
	std::string getTagContent();

private:
	ElementList itemsList;

public:
	/**
		ctor
	*/
	MenuList(std::string name);

	/**
		dtor
	*/
	~MenuList();

	void addItem(std::string item, CALLBACk_HANDLE handl, std::string pluginName);
};




}
}
}
}


#endif



