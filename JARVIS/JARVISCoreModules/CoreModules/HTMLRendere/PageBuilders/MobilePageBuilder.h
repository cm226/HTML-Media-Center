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
	std::string publicURL;
	std::stringstream page;
	std::vector<IElement*>* elements;

	inline void calcPublicURL(int aditionalContextLength);

	void buildHeader();

	void buildCSSIncludes(std::list<std::string> cssIncludes);
	void buildJSIncludes(std::list<std::string> jsIncludes);
	void buildEmbeddedJS(std::string code);

	void buildJqueryHeader();
	void buildBody();
	void buildFooter();

public:
	MobilePageBuilder(int aditionalContextLength);
	virtual ~MobilePageBuilder();

	void buildPage(std::string* page, std::vector<IElement*>* elements);
};

#endif /* MOBILEPAGEBUILDER_H_ */
