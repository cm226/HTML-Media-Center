/*
 * Dependancy.cpp
 *
 *  Created on: 22 Apr 2013
 *      Author: craig
 */

#include "Dependancy.h"

namespace CodeGenerators {

Dependancy::Dependancy() {
	// TODO Auto-generated constructor stub

}

Dependancy::~Dependancy() {
	// TODO Auto-generated destructor stub
}

void Dependancy::setPathToDependancy(std::string path)
{
	this->pathToDependacyFile = path;
}
std::string Dependancy::getPathToDependancy()
{
	return this->pathToDependacyFile;
}

void Dependancy::setDependancyName(std::string name)
{
	this->dependancyName = name;
}
std::string Dependancy::getDependancyName()
{
	return this->dependancyName;
}

void Dependancy::setStandardLibraryDependancy(std::string dep)
{
	this->standardLibraryDependancy = dep;
}

std::string Dependancy::getStandardLibraryDependancy()
{
	return this->standardLibraryDependancy;
}

} /* namespace CodeGenerators */
