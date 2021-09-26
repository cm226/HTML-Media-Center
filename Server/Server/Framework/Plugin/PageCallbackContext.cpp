/*
 * Plugin.cpp
 *
 *  Created on: Sep 4, 2012
 *      Author: craig
 */

#include "PageCallbackContext.h"


void PageCallbackContext::parsePageContext()
{
	std::size_t keyValIndicatorPos;
	for (std::vector<std::string>::iterator contextStart = this->aditionalContextInfo.begin();
			contextStart != this->aditionalContextInfo.end();
			contextStart++)
	{
		keyValIndicatorPos = contextStart->find('=');
		if (keyValIndicatorPos != std::string::npos)
		{
			if (keyValIndicatorPos + 1 >= contextStart->size())
				aditionalContextInfoKeyVal[contextStart->substr(0, keyValIndicatorPos)] = "";
			else
				aditionalContextInfoKeyVal[contextStart->substr(0, keyValIndicatorPos)] =
					contextStart->substr(keyValIndicatorPos+1);
			

		}
	}
}


void PageCallbackContext::setAdditionalContext(std::vector<std::string>* context)
{

	this->aditionalContextInfo = *context;
	this->parsePageContext();
}
