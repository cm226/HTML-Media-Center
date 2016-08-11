/*
 * IContainer.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef ICONTAINER_H_
#define ICONTAINER_H_

#include "../IElement.h"

#include <vector>
#include "../../exportMacros.h"

class DLLCORE_API IContainer : public IElement{

public:
	IContainer(std::string name);
	virtual ~IContainer();

	virtual void addElement(IElement* element) = 0;
	virtual void removeElement(IElement* element) =0;


};

#endif /* ICONTAINER_H_ */
