/*
 * PageBuilder.cpp
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#include "PageBuilder.h"

PageBuilder::PageBuilder() {
	// TODO Auto-generated constructor stub

}

PageBuilder::~PageBuilder() {
	// TODO Auto-generated destructor stub
}


void PageBuilder::buildHeader()
{
	// we dont have a header yet?
}
void PageBuilder::buildHTMLHeadElement()
{
	this->page << "<head>";
	std::vector<IElement*>::iterator elementIt;
	for(elementIt = this->elements->begin(); elementIt != this->elements->end(); elementIt++)
	{
		std::list<std::string> jsFiles = (*elementIt)->getJSIncludes();
		std::list<std::string> cssFile = (*elementIt)->getCSSIncludes();

		for(std::list<std::string>::iterator jsFileIt = jsFiles.begin(); jsFileIt != jsFiles.end(); jsFileIt++)
			buildJSInclude(*jsFileIt);

		for(std::list<std::string>::iterator cssFileIt = cssFile.begin(); cssFileIt != cssFile.end(); cssFileIt++)
			buildCSSInclude(*cssFileIt);
	}
	this->page << "</head>";
}

void PageBuilder::buildCSSInclude(std::string path)
{
	this->page << "<LINK href=\" " << path<< "\" rel=\"stylesheet\" type=\"text/css\">";
}

void PageBuilder::buildJSInclude(std::string path)
{
	this->page << "<script type=\"text/JavaScript\" src=\" " << path << "\"></script>";
}

void PageBuilder::buildBody()
{
	for(std::vector<IElement*>::iterator it =  this->elements->begin(); it != this->elements->end(); it++)
	{
		this->page << ((*it)->getText());
	}

}
void PageBuilder::buildFooter()
{

}

void PageBuilder::buildPage(std::string* page, std::vector<IElement*>* elements)
{
	this->elements = elements;

	this->buildHeader();
	this->buildHTMLHeadElement();
	this->buildBody();
	this->buildFooter();

	*page = this->page.str();
}

