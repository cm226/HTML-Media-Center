/*
 * GenericClass.cpp
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */


#include "GenericClass.h"

namespace CodeGenerators
{

GenericClass::GenericClass(const std::string* name)
						: baseClass(Types::UNSPECIFIED,"")
{
	this->name = std::string(*name);

	this->publicMethods.push_back(Method(*name));
	this->publicMethods.push_back(Method("~"+*name));

	this->getConstructor()->setReturnType(Types(" "));
	this->getDeConstructor()->setReturnType(Types(" "));

	this->baseClassValid = false;
}

GenericClass::~GenericClass()
{
}

Method* GenericClass::getConstructor()
{
	return &this->publicMethods[0]; // this is a really stupid idea
}
Method* GenericClass::getDeConstructor()
{
	return &this->publicMethods[1]; // so is this
}

void GenericClass::addBaseClass(Member& base)
{
	this->baseClassValid = true;
	this->baseClass = base;
}

bool GenericClass::getBaseClass(Member& baseClass)
{
	if(!this->baseClassValid)
		return false;

	baseClass = this->baseClass;
	return true;
}

void GenericClass::setPostClassModifierString(std::string postClassMod)
{
	this->postClassModStr = postClassMod;
}
void GenericClass::setPreClassModString(std::string preClassModStr)
{
	this->preClassModString= preClassModStr;
}
bool GenericClass::getPostClassModifierString(std::string& postClassMod)
{
	if(this->postClassModStr.compare("") != 0)
	{
		postClassMod = this->postClassModStr;
		return true;
	}
	return false;
}


bool GenericClass::getPreClassModifierString(std::string& preClassMod)
{
	if(this->preClassModString.compare("") != 0)
	{
		preClassMod = this->preClassModString;
		return true;
	}
	return false;
}



}
