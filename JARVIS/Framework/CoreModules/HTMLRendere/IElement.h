/*
 * IElement.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef IELEMENT_H_
#define IELEMENT_H_

#include <string>

class IElement {

	std::string name;
public:
	IElement(std::string name);
	virtual ~IElement();
};

#endif /* IELEMENT_H_ */
