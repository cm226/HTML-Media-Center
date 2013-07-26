/*
 * MobilePageBuilder.cpp
 *
 *  Created on: 25 Jul 2013
 *      Author: craig
 */

#include "MobilePageBuilder.h"

MobilePageBuilder::MobilePageBuilder() {
	// TODO Auto-generated constructor stub

}

MobilePageBuilder::~MobilePageBuilder() {
	// TODO Auto-generated destructor stub
}


void MobilePageBuilder::buildHeader()
{
	buildCSSIncludes();
	buildJSIncludes();
	buildEmbeddedJS();
	page << "</head>";
	page << "<body><div data-role=\"page\" data-theme=\"a\">";
}

void MobilePageBuilder::buildCSSIncludes()
{

}

void MobilePageBuilder::buildJSIncludes()
{

}

void MobilePageBuilder::buildEmbeddedJS()
{

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

	page << "</div>";


}

void MobilePageBuilder::buildBody()
{

}

void MobilePageBuilder::buildFooter()
{
	page << "</div></body>";
}

void MobilePageBuilder::buildPage(std::string* page, std::vector<IElement*>* elements)
{
	this->elements = elements;

	buildHeader();
	buildJqueryHeader();
	buildBody();
	buildFooter();

	*page = this->page.str();
}

