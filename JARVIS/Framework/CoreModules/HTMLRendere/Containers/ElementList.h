/*
 * ElementList.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef ELEMENTLIST_H_
#define ELEMENTLIST_H_

#include "IContainer.h"

class ElementList: public IContainer {
public:
	ElementList();
	virtual ~ElementList();

	void addElement(IElement element);
	void removeElement(IElement element);
};

#endif /* ELEMENTLIST_H_ */
