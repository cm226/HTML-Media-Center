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

public:
	IElement(std::string name);

	virtual std::string getText() = 0;
	virtual ~IElement();

	std::string name;
};

#endif /* IELEMENT_H_ */
