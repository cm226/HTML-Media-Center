/*
 * IPageBuilder.h
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#ifndef IPAGEBUILDER_H_
#define IPAGEBUILDER_H_

#include <vector>
#include <string>

class IPageBuilder
{
public:
	IPageBuilder(){}
	virtual ~IPageBuilder(){};

	virtual void buildPage(std::string* page, std::vector<IElement*>* elements) = 0;
};

#endif
