/*
 * FormSubmit.h
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#ifndef FORMSUBMIT_H_
#define FORMSUBMIT_H_

#include "../IElement.h"
#include <string>

#include "../../exportMacros.h"

class DLLCORE_API FormSubmit : public IElement {
public:
	FormSubmit(std::string name);
	virtual ~FormSubmit();

	virtual std::string getText();
};

#endif /* FORMSUBMIT_H_ */
