/*
 * IElement.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef IELEMENT_H_
#define IELEMENT_H_

#include <string>
#include <sstream>
#include <vector>
#include <list>
#include "../exportMacros.h"
#include "../../../JARVIS/Framework/Plugin/HTMLCALLBACKDef.h"

class DLLCORE_API IElement {
private:
	#pragma warning( disable : 4251)
	std::vector<std::string> attributes;
	std::list<std::string> styles;
	std::list<std::string> cssFiles;
	std::list<std::string> javascriptFiles;
	std::stringstream embededJSCode;
	std::string name;
	#pragma warning( default : 4251)
	std::string writeStyle();
	

protected:
	virtual std::string getTagText() = 0;
	virtual std::string getTagContent() = 0;
	virtual std::string writeAttributes();

public:
	IElement(std::string name);
	virtual ~IElement();

	void addAttribute(std::string att);
	void addStyle(std::string name, std::string value);
	void includeCSS(std::string cssPath);
	void includeJS(std::string jsPath);
	void appendEmbeddedJSCode(std::string code);

	void addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName, std::vector<std::string> contextArgs);
	void addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName);
	
	//TODO implement asinc onclick finctions
	//void addAsincOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName);
	//void addAsincOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName, std::vector<std::string> contextArgs);

	virtual std::string getText();

	std::list<std::string>& getJSIncludes();
	std::list<std::string>& getCSSIncludes();
	std::string getEmbeddedJS();
	

};

#endif /* IELEMENT_H_ */
