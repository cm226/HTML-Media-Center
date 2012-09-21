/*
 * ElementList.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef ELEMENTLIST_H_
#define ELEMENTLIST_H_

#include "IContainer.h"

#include <vector>

class ElementList: public IContainer {

private :
	std::vector<IElement*> elements;

public:
	ElementList(std::string name);
	virtual ~ElementList();

	void addElement(IElement* element);
	void removeElement(IElement* element);
	std::string getText();
};

#endif /* ELEMENTLIST_H_ */
