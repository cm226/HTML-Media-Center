/*
 * FormSubmit.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#include "FormSubmit.h"

FormSubmit::FormSubmit(std::string name): IElement(name) 
{
	this->addAttribute("type=\"submit\"");
	this->addAttribute("value=\"submit\"");
}

FormSubmit::~FormSubmit() {
}

std::string FormSubmit::getTagText()
{
	return "input";
}

std::string FormSubmit::getTagContent()
{
	return "";
}
