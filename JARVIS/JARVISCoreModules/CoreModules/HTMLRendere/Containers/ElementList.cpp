/*
 * ElementList.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "ElementList.h"
#include <sstream>

ElementList::ElementList(std::string name): IContainer(name) {

}

ElementList::~ElementList() {
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

std::string ElementList::getTagContent()
{
	std::stringstream ss;

	for(std::vector<IElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		ss << (*it)->getText();
	}

	return ss.str();
}

