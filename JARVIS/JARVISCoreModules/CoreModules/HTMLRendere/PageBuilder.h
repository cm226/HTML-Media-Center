/*
 * PageBuilder.h
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#ifndef PAGEBUILDER_H_
#define PAGEBUILDER_H_

#include <vector>
#include <string>
#include <sstream>
#include "IElement.h"


class PageBuilder
{
private:
	std::stringstream page;
	std::vector<IElement*>* elements;

	void buildHeader();
	void buildHTMLHeadElement();
	void buildCSSInclude(std::string path);
	void buildJSInclude(std::string path);
	void buildBody();
	void buildFooter();

public:
	PageBuilder();
	virtual ~PageBuilder();

	void buildPage(std::string* page, std::vector<IElement*>* elements);
};

#endif /* PAGEBUILDER_H_ */
