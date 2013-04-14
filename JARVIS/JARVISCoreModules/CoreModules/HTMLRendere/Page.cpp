/*
 * Page.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "Page.h"
#include <sstream>

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
		if(*it)
		{
			delete *it;	
			*it = NULL;
		}
	}
}

void Page::buildPage(std::string* page)
{
	std::stringstream pageBuilder;
	for(std::vector<IElement*>::iterator it =  this->elements.begin(); it != this->elements.end(); it++)
	{
		pageBuilder << ((*it)->getText());
	}

	*page = pageBuilder.str();
}
