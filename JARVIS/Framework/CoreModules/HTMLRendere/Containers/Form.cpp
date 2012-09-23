/*
 * Form.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#include "Form.h"

Form::Form(std::string name) : IContainer(name) {
	// TODO Auto-generated constructor stub

}

Form::~Form() {
	// TODO Auto-generated destructor stub
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

std::string Form::getText()
{
	std::string value = "<form id="+this->name+" action=\"../Shared/genericPluginFormHandler\">";
	for(std::vector<IElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
		{
			value.append((*it)->getText());
		}
	value.append("</form>");
	return value;
}
