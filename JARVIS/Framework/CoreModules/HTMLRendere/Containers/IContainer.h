/*
 * IContainer.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef ICONTAINER_H_
#define ICONTAINER_H_

#include "../IElement.h";

class IContainer : IElement{
public:
	IContainer();
	virtual ~IContainer();

	virtual void addElement(IElement element);
	virtual void removeElement(IElement element);


};

#endif /* ICONTAINER_H_ */
