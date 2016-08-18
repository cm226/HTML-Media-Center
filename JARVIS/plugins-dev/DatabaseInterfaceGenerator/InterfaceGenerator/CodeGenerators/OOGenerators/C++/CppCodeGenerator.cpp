/*
 * CppCodeGenerator.cpp
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#include "CppCodeGenerator.h"

#include "CppClass.h"
#include "CppHeader.h"

namespace CodeGenerators {

CppCodeGenerator::CppCodeGenerator(std::string fileName): AbstractOOCodeGenerator(fileName)
{
	this->nameSpace = "";

}

CppCodeGenerator::~CppCodeGenerator() {
}

void CppCodeGenerator::addClass(GenericClass gclass)
{
	this->classes.push_back(gclass);
}

void CppCodeGenerator::save()
{
	std::vector<GenericClass>::iterator classit;
	for(classit = this->classes.begin(); classit != this->classes.end(); classit++)
	{
		CppClass classWriter(&(*classit));
		CppHeader headerWriter(&(*classit));

		classWriter.write(&this->fileName);
		headerWriter.write(&this->fileName);

	}
}


} /* namespace CodeGenerators */
