/*
 * IElement.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "IElement.h"


IElement::IElement(std::string name)
{
	this->addAttribute("id=\""+name+"\"");
}

IElement::~IElement() 
{
}

void IElement::addAttribute(std::string attribute)
{
	this->attributes.push_back(attribute);
}

void IElement::addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName, std::vector<std::string>  contextArgs)
{
	std::stringstream movieAttributeStream ;
	movieAttributeStream << "onClick=\"window.location='";
	movieAttributeStream << buildCallbackLocationString(depth, handl, pluginName, contextArgs);
	movieAttributeStream << "'\"";
	this->addAttribute(movieAttributeStream.str());
}

void IElement::addOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName)
{	
	std::stringstream movieAttributeStream ;
	movieAttributeStream << "onClick=\"window.location='";
	movieAttributeStream << buildCallbackLocationString(depth, handl, pluginName) <<"'\"";;
	this->addAttribute(movieAttributeStream.str());
}

std::string IElement::buildCallbackLocationString(int depth, CALLBACk_HANDLE handl, std::string pluginName, std::vector<std::string> contextArgs,std::string location)
{
	std::stringstream locationStream ;

	for(int i = 0; i < depth; i++)
		locationStream << "../";
	locationStream<<location<<"/";	
	
	locationStream << handl << "/" << pluginName;
	std::vector<std::string>::iterator contextArgsIt;
	for(contextArgsIt = contextArgs.begin(); contextArgsIt != contextArgs.end(); contextArgsIt++)
		locationStream << "/"<<*contextArgsIt;

	return locationStream.str();
}

std::string IElement::buildCallbackLocationString(int depth, CALLBACk_HANDLE handl, std::string pluginName,std::string location)
{
	std::stringstream locationStream ;
	
	for(int i = 0; i < depth; i++)
		locationStream << "../";
	locationStream<<location<<"/";		

	locationStream << handl << "/" << pluginName;

	return locationStream.str();
}

/*

void addAsincOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName)
{

}

void addAsincOnclickCallbackAttribute(int depth, CALLBACk_HANDLE handl, std::string pluginName, std::vector<std::string> contextArgs)
{

}
*/
std::string IElement::writeStyle()
{
	if(this->styles.size() == 0)
		return "";

	std::stringstream stylestream;
	
	stylestream << " style=\"";
	std::list<std::string>::iterator stylesIt;
	for(stylesIt = this->styles.begin(); stylesIt != this->styles.end(); stylesIt++)
	{
		stylestream << *stylesIt;
	}
	stylestream << "\"";
	return stylestream.str();
}

std::string IElement::writeAttributes()
{
	std::stringstream stributeHTML;

	std::vector<std::string>::iterator attributeIt;
	for(attributeIt = this->attributes.begin(); attributeIt != this->attributes.end(); attributeIt++)
		stributeHTML << " " << (*attributeIt);

	stributeHTML << this->writeStyle();
	return stributeHTML.str();
}

void IElement::addStyle(std::string name, std::string value)
{
	this->styles.push_back(name + ":" + value+";");
}

void IElement::includeCSS(std::string cssPath)
{
	this->cssFiles.push_back(cssPath);
}

void IElement::includeJS(std::string jsPath)
{
	this->javascriptFiles.push_back(jsPath);
}

void IElement::appendEmbeddedJSCode(std::string code)
{
	this->embededJSCode << code;
}

void IElement::appendJQueryMobileHeaderContent(std::string html)
{
	this->jQueryMobileHeaderContent << html;
}

std::string IElement::getText()
{
	std::stringstream elementHTML;
	std::string tagTxt = this->getTagText();
	elementHTML << "<" <<tagTxt;
	elementHTML << writeAttributes() << ">";
	elementHTML << getTagContent();
	elementHTML << "</" << this->getTagText() << ">";

	return elementHTML.str();
}

std::string IElement::getMobileText()
{
	std::stringstream elementHTML;
	std::string tagTxt = this->getTagMobileText();
	if(tagTxt.length() != 0)
		elementHTML << "<" <<tagTxt;

	elementHTML << writeAttributes() << ">";
	elementHTML << getMobileTagContent();

	if(tagTxt.length() != 0)
		elementHTML << "</" << this->getTagText() << ">";

	return elementHTML.str();

}


std::list<std::string>& IElement::getJSIncludes()
{
	return this->javascriptFiles;
}
std::list<std::string>& IElement::getCSSIncludes()
{
	return this->cssFiles;
}

std::string IElement::getEmbeddedJS()
{
	return this->embededJSCode.str();
}

std::string IElement::getJQueryMobileHeaderContent()
{
	return this->jQueryMobileHeaderContent.str();
}
