/*
 * Plugin.h
 *
 *  Created on: Sep 4, 2012
 *      Author: craig
 */

#ifndef PAGE_CALLBACK_CONTEXT_H_
#define PAGE_CALLBACK_CONTEXT_H_

#include "HTMLCALLBACKDef.h"
#include <string>
#include <vector>
#include <map>

class PageCallbackContext {

private:
	std::vector<std::string> aditionalContextInfo;
	std::map<std::string, std::string> aditionalContextInfoKeyVal;

	void parsePageContext();
protected:

public:
	PageCallbackContext(){};
	~PageCallbackContext(){};

	void setAdditionalContext(std::vector<std::string>* context);
	std::vector<std::string> getAdditionalContext(){return this->aditionalContextInfo;}
	std::map<std::string, std::string> getKeyValueAdditionalContext() { return this->aditionalContextInfoKeyVal; }

	CALLBACk_HANDLE callbackHandle;



};

#endif
