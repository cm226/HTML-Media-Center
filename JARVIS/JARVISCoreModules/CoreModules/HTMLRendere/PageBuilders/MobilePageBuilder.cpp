/*
 * MobilePageBuilder.cpp
 *
 *  Created on: 25 Jul 2013
 *      Author: craig
 */

#include "MobilePageBuilder.h"
#include "../../config.h"

MobilePageBuilder::MobilePageBuilder() {
	// TODO Auto-generated constructor stub

}

MobilePageBuilder::~MobilePageBuilder() {
	// TODO Auto-generated destructor stub
}


void MobilePageBuilder::buildHeader()
{
	page << "<!DOCTYPE html>\
<html>\
<head>\
<title>Is this thing on?</title>\
\<script type=\"text/javascript\" src='" << HTMLMEDIAPUBLIC << "/js/helperFunctions.js'></script>\
<script type=\"text/javascript\" src='" << HTMLMEDIAPUBLIC << "/js/jquery-1.10.1.min.js'></script>\
<script type=\"text/javascript\" src='" << HTMLMEDIAPUBLIC << "/js/jquery.mobile-1.3.1.min.js'></script>\
<link rel=\"stylesheet\" href='" << HTMLMEDIAPUBLIC << "/css/Mobile/jquery.mobile-1.3.1.min.css'/>\
<link rel=\"stylesheet\" type=\"text/css\" href='" << HTMLMEDIAPUBLIC << "/css/Mobile/genericStyle.css'>\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, maximum-scale=1\">";

	for(std::vector<IElement*>::iterator it =  this->elements->begin(); it != this->elements->end(); it++)
	{
		buildCSSIncludes((*it)->getCSSIncludes());
		buildEmbeddedJS((*it)->getEmbeddedJS());
		buildJSIncludes((*it)->getJSIncludes());
	}
	page << "</head>";

}

void MobilePageBuilder::buildCSSIncludes(std::list<std::string> cssIncludes)
{
		for(std::list<std::string>::iterator includeIt = cssIncludes.begin();
			includeIt != cssIncludes.end(); includeIt++)
				page << "<LINK href=\" " << (*includeIt)<< "\" rel=\"stylesheet\" type=\"text/css\">";
}

void MobilePageBuilder::buildJSIncludes(std::list<std::string> jsIncludes)
{
	for(std::list<std::string>::iterator includeIt = jsIncludes.begin();
		includeIt != jsIncludes.end(); includeIt++)
		this->page << "<script type=\"text/JavaScript\" src=\" " << *includeIt<< "\"></script>";
}

void MobilePageBuilder::buildEmbeddedJS(std::string code)
{
	this->page << "<script type=\"text/JavaScript\"> " << code << "</script>";
}

void MobilePageBuilder::buildJqueryHeader()
{
	page << "<div data-role=\"header\" >"
		 <<"<h1>Plugins</h1>"
		 <<"<div data-role=\"navbar\">"
		 <<"<ul>"
		 <<"<li><a href=\"../Start/Home\">Media Center</a></li>"
		 <<"<li><a href=\"../Plugin/Main\">Plugin Main</a></li>"
		 <<"</ul>"
		 <<"</div>";

	for(std::vector<IElement*>::iterator it =  this->elements->begin(); it != this->elements->end(); it++)
	{
		page << (*it)->getJQueryMobileHeaderContent();
	}

	page << "</div>";


}

void MobilePageBuilder::buildBody()
{
	page << "<div data-role=\"content\">";

	for(std::vector<IElement*>::iterator it =  this->elements->begin(); it != this->elements->end(); it++)
	{
		std::string elementBody =(*it)->getMobileText();
		this->page << elementBody;
	}
	page << "</div>";
}

void MobilePageBuilder::buildFooter()
{

}

void MobilePageBuilder::buildPage(std::string* page, std::vector<IElement*>* elements)
{
	this->elements = elements;

	buildHeader();
	this->page << "<body><div data-role=\"page\" data-theme=\"a\">";

	buildJqueryHeader();
	buildBody();

	this->page << "</div></body>";
	buildFooter();

	*page = this->page.str();
}

