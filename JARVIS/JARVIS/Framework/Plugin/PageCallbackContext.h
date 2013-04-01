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

class PageCallbackContext {

private:
	std::vector<std::string> aditionalContextInfo;
protected:

public:
	PageCallbackContext();
	~PageCallbackContext();

	void setAdditionalContext(std::vector<std::string>* context){this->aditionalContextInfo = * context;}
	std::vector<std::string> getAdditionalContext(){return this->aditionalContextInfo;}

	CALLBACk_HANDLE callbackHandle;



};

#endif
