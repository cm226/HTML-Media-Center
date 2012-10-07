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

class Page {
private:
	std::vector<IElement*> elements;

public:

	Page();
	virtual ~Page();

	void addElement(IElement* element);
	void freePage();
	void buildPage(std::string* page);
};


#endif /* PAGE_H_ */
