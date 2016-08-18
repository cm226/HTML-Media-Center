/*
 * Form.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#include "Form.h"
#include <sstream>

Form::Form(std::string name) : IContainer(name) {
	this->addAttribute("method=\"POST\"");
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
	std::vector<IElement*>::iterator it;
	for(it = elements.begin(); it != elements.end(); ++it)
	{
		if(*it == element)
			break;
	}
	elements.erase(it);
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

void Form::setHandler(int depth, CALLBACk_HANDLE handl, std::string pluginName)
{
	std::stringstream actionCallback;
	actionCallback << "action=\"" << buildCallbackLocationString(depth, handl, pluginName) << "\"";
	this->addAttribute(actionCallback.str());
	;
}
