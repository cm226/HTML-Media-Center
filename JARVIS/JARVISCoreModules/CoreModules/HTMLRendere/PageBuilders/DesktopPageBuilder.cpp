/*
 * PageBuilder.cpp
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#include "DesktopPageBuilder.h"

DesktopPageBuilder::DesktopPageBuilder() {
	// TODO Auto-generated constructor stub

}

DesktopPageBuilder::~DesktopPageBuilder() {
	// TODO Auto-generated destructor stub
}


void DesktopPageBuilder::buildHeader()
{
	// we dont have a header yet?
}
void DesktopPageBuilder::buildHTMLHeadElement()
{
	std::vector<IElement*>::iterator elementIt;
	for(elementIt = this->elements->begin(); elementIt != this->elements->end(); elementIt++)
	{
		std::list<std::string> jsFiles = (*elementIt)->getJSIncludes();
		std::list<std::string> cssFile = (*elementIt)->getCSSIncludes();

		std::string embeddedJS = (*elementIt)->getEmbeddedJS();
		if(embeddedJS.size() > 0)
			buildEmbeddedJS(embeddedJS);

		for(std::list<std::string>::iterator jsFileIt = jsFiles.begin(); jsFileIt != jsFiles.end(); jsFileIt++)
			buildJSInclude(*jsFileIt);

		for(std::list<std::string>::iterator cssFileIt = cssFile.begin(); cssFileIt != cssFile.end(); cssFileIt++)
			buildCSSInclude(*cssFileIt);
	}
}

void DesktopPageBuilder::buildCSSInclude(std::string path)
{
	this->page << "<LINK href=\" " << path<< "\" rel=\"stylesheet\" type=\"text/css\">";
}

void DesktopPageBuilder::buildJSInclude(std::string path)
{
	this->page << "<script type=\"text/JavaScript\" src=\" " << path << "\"></script>";
}

void DesktopPageBuilder::buildEmbeddedJS(std::string jsCode)
{
	this->page << "<script type=\"text/JavaScript\"> " << jsCode << "</script>";
}

void DesktopPageBuilder::buildBody()
{
	for(std::vector<IElement*>::iterator it =  this->elements->begin(); it != this->elements->end(); it++)
	{
		std::string elementBody =(*it)->getText();
		this->page << elementBody;
	}

}
void DesktopPageBuilder::buildFooter()
{

}

void DesktopPageBuilder::buildPage(std::string* page, std::vector<IElement*>* elements)
{
	this->elements = elements;

	this->buildHeader();
	this->buildHTMLHeadElement();
	this->buildBody();
	this->buildFooter();

	*page = this->page.str();
}

