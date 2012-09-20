/*
 * ElementList.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "ElementList.h"

ElementList::ElementList(std::string name): IContainer(name) {
	// TODO Auto-generated constructor stub

}

ElementList::~ElementList() {
	// TODO Auto-generated destructor stub
}

void ElementList::addElement(IElement* element)
{
	elements.push_back(element);
}

void ElementList::removeElement(IElement* element)
{
	for(std::vector<IElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if(*it == element)
			elements.erase(it);
	}
}

std::string ElementList::getText()
{
	std::string value = "<div id="+this->name+">";
	for(std::vector<IElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
		{
			value.append((*it)->getText());
		}
	value.append("</div>");
	return value;
}

