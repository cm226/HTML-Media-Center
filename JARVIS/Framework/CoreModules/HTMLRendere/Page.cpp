/*
 * Page.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "Page.h"

Page::Page() {


}

Page::~Page() {
}

void Page::addElement(IElement* element)
{
	this->elements.push_back(element);
}

void Page::freePage()
{
	for(std::vector<IElement*>::iterator it =  this->elements.begin(); it != this->elements.end(); it++)
	{
		delete *it;
	}
}

void Page::buildPage(std::string* page)
{
	for(std::vector<IElement*>::iterator it =  this->elements.begin(); it != this->elements.end(); it++)
	{
		page->append((*it)->getText());
	}
}
