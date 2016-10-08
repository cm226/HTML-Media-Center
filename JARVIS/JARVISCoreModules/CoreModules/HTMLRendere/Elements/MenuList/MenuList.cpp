/*
	Author : Craig Matear
*/
#include "MenuList.h"
#include "../Lable.h"


namespace coremodules {
namespace htmlrendere {
namespace elements {
namespace menulist {


 
MenuList::MenuList(std::string name) : IElement(name), itemsList(name+"ItemList")
{
	includeCSS("../../public/css/HTMLRendereCSS/menuItem.css");
	addAttribute("class='menuContainer'");
}



MenuList::~MenuList()
{
}

std::string MenuList::getTagText()
{
	return "div";
}
std::string MenuList::getTagContent()
{
	return this->itemsList.getText();
}

void MenuList::addItem(std::string item, CALLBACk_HANDLE handl, std::string pluginName)
{
	Lable* newItem = new Lable("MenuItem");
	newItem->addAttribute("class='menuItem'");
	newItem->setText(item);
	newItem->addOnclickCallbackAttribute(handl, pluginName);

	this->itemsList.addElement(newItem);
}



}
}
}
}



