/*
 * Page.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef PAGE_H_
#define PAGE_H_

#include "IElement.h"
#include <vector>
#include <string>

#include "../exportMacros.h"

class DLLCORE_API Page {
private:
	#pragma warning( disable : 4251)
	std::vector<IElement*> elements;
	#pragma warning( default : 4251)

public:

	Page();
	virtual ~Page();

	void addElement(IElement* element);
	void freePage();
	void buildPage(std::string* page);
	void buildMobilePage(std::string* page);
};


#endif /* PAGE_H_ */
