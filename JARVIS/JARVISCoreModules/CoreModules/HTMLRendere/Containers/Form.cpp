/*
 * Form.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#include "Form.h"
#include <sstream>

Form::Form(std::string name) : IContainer(name) {
	this->addAttribute("action=\"../Shared/genericPluginFormHandler\"");

}

Form::~Form() {
	for(std::vector<IElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		delete *it;

	}
}

void Form::addElement(IElement* element)
{
	elements.push_back(element);
}

void Form::removeElement(IElement* element)
{
	for(std::vector<IElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if(*it == element)
			elements.erase(it);
	}
}


std::string Form::getTagContent()
{
	std::stringstream ss;

	for(std::vector<IElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		ss << (*it)->getText();
	}

	return ss.str();
}
