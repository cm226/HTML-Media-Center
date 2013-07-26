/*
 * Page.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "Page.h"
#include "PageBuilders/DesktopPageBuilder.h"
#include "PageBuilders/MobilePageBuilder.h"
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
	DesktopPageBuilder pageBuilder;
	pageBuilder.buildPage(page, &this->elements);
}

void Page::buildMobilePage(std::string* page)
{
	MobilePageBuilder mobilePageBuilder;
	mobilePageBuilder.buildPage(page, &this->elements);
}
