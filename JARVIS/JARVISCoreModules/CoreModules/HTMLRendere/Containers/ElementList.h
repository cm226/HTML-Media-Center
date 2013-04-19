/*
 * ElementList.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef ELEMENTLIST_H_
#define ELEMENTLIST_H_

#include "IContainer.h"
#include "../../exportMacros.h"

#include <vector>

class DLLCORE_API ElementList: public IContainer {

private :
	#pragma warning( disable : 4251)
	std::vector<IElement*> elements;
	#pragma warning( default : 4251)

protected:
	std::string getTagText(){return "div";};
	std::string getTagContent();

public:
	ElementList(std::string name);
	virtual ~ElementList();

	void addElement(IElement* element);
	void removeElement(IElement* element);

};

#endif /* ELEMENTLIST_H_ */
