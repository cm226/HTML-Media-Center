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
#include "../../exportMacros.h"

class DLLCORE_API Form : public IContainer
{
private:
	#pragma warning( disable : 4251)
	std::vector<IElement*> elements;
	#pragma warning( default : 4251)

protected:
	std::string getTagText(){return "form";};
	std::string getTagContent();

public:
	Form(std::string name);
	virtual ~Form();

	virtual void addElement(IElement* element);
	virtual void removeElement(IElement* element);
	virtual void setHandler(int depth, CALLBACk_HANDLE handl, std::string pluginName);

};

#endif /* FORM_H_ */
