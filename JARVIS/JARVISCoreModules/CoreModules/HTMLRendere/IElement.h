/*
 * IElement.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef IELEMENT_H_
#define IELEMENT_H_

#include <string>
#include <vector>
#include "../exportMacros.h"
#include "../../../JARVIS/Framework/Plugin/HTMLCALLBACKDef.h"

class DLLCORE_API IElement {
private:
	#pragma warning( disable : 4251)
	std::vector<std::string> attributes;
	std::string name;
	#pragma warning( default : 4251)

protected:
	virtual std::string getTagText() = 0;
	virtual std::string getTagContent() = 0;

public:
	IElement(std::string name);
	virtual ~IElement();

	void addAttribute(std::string att);
	void addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName, std::vector<std::string> contextArgs);
	void addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName);
	virtual std::string getText();

};

#endif /* IELEMENT_H_ */
