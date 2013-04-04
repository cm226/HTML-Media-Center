/*
 * IElement.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "IElement.h"
#include <sstream>

using namespace std;

IElement::IElement(string name) {
	this->addAttribute("name = '"+name+"'");
}

IElement::~IElement() {
	// TODO Auto-generated destructor stub
}

void IElement::addAttribute(std::string attribute)
{
	this->attributes.push_back(attribute);
}

void IElement::addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName, std::string contextArgs)
{
	std::stringstream movieAttributeStream ;
	movieAttributeStream << "onClick=\"window.location = '";
	for(int i = 0; i < depth; i++)
		movieAttributeStream << "../";
	movieAttributeStream<<"pluginInteraction/";	
	
	movieAttributeStream << handl << "/" << pluginName << "/" << contextArgs <<"'\"";

	this->addAttribute(movieAttributeStream.str());
}

void IElement::addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName)
{
std::stringstream movieAttributeStream ;
	movieAttributeStream << "onClick=\"window.location = '";
	for(int i = 0; i < depth; i++)
		movieAttributeStream << "../";
	movieAttributeStream<<"pluginInteraction/";	

	movieAttributeStream << handl << "/" << pluginName  <<"'\"";

	this->addAttribute(movieAttributeStream.str());
}

std::string IElement::getText()
{
	std::stringstream elementHTML;
	elementHTML << "<" <<this->getTagText();

	std::vector<std::string>::iterator attributeIt;
	for(attributeIt = this->attributes.begin(); attributeIt != this->attributes.end(); attributeIt++)
		elementHTML << " " << (*attributeIt) << " ";

	elementHTML << ">"<< getTagContent();
	elementHTML << "</" << this->getTagText() << ">";

	return elementHTML.str();
}
