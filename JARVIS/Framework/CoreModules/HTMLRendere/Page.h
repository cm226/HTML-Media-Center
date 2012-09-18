/*
 * Page.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef PAGE_H_
#define PAGE_H_

#include "IElement.h"

class Page {
public:
	Page();
	virtual ~Page();

	void addElement(IElement* element);

};

#endif /* PAGE_H_ */
