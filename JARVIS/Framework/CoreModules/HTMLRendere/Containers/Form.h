/*
 * Form.h
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#ifndef FORM_H_
#define FORM_H_

#include <vector>
#include "IContainer.h"

class Form : public IContainer
{
private:
	std::vector<IElement*> elements;
public:
	Form(std::string name);
	virtual ~Form();

	virtual void addElement(IElement* element);
	virtual void removeElement(IElement* element);

	std::string getText();
};

#endif /* FORM_H_ */
