/*
 * MobilePageBuilder.h
 *
 *  Created on: 25 Jul 2013
 *      Author: craig
 */

#ifndef MOBILEPAGEBUILDER_H_
#define MOBILEPAGEBUILDER_H_

#include <sstream>

#include "DesktopPageBuilder.h"


class MobilePageBuilder : public IPageBuilder
{
private:
	std::stringstream page;
	std::vector<IElement*>* elements;

	void buildHeader();
	void buildCSSIncludes();
	void buildJSIncludes();
	void buildEmbeddedJS();

	void buildJqueryHeader();
	void buildBody();
	void buildFooter();

public:
	MobilePageBuilder();
	virtual ~MobilePageBuilder();

	void buildPage(std::string* page, std::vector<IElement*>* elements);
};

#endif /* MOBILEPAGEBUILDER_H_ */
