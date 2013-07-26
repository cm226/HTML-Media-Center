/*
 * PageBuilder.h
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#ifndef PAGEBUILDER_H_
#define PAGEBUILDER_H_


#include <sstream>

#include "IPageBuilder.h"
#include "IElement.h"


class DesktopPageBuilder : public IPageBuilder
{
private:
	std::stringstream page;
	std::vector<IElement*>* elements;

	void buildHeader();
	void buildHTMLHeadElement();
	void buildCSSInclude(std::string path);
	void buildJSInclude(std::string path);
	void buildEmbeddedJS(std::string jsCode);

	void buildBody();
	void buildFooter();

public:
	DesktopPageBuilder();
	virtual ~DesktopPageBuilder();

	void buildPage(std::string* page, std::vector<IElement*>* elements);
};

#endif /* PAGEBUILDER_H_ */
