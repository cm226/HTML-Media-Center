/*
 * Lable.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef LABLE_H_
#define LABLE_H_

#include "IElement.h"

class Lable: public IElement {
public:
	Lable(std::string name);
	virtual ~Lable();
};

#endif /* LABLE_H_ */
