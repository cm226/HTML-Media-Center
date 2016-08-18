/*
 * CppCodeGenerator.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef CPPCODEGENERATOR_H_
#define CPPCODEGENERATOR_H_

#include "../AbstractOOCodeGenerator.h"
#include "CppClass.h"

#include <string>
#include <vector>

namespace CodeGenerators {

class CppCodeGenerator: public AbstractOOCodeGenerator {
private:
	std::vector<GenericClass> classes;
	std::string nameSpace;

public:
	CppCodeGenerator(std::string filename);
	virtual ~CppCodeGenerator();

	void addClass(GenericClass gclass);

	void save();
};

} /* namespace CodeGenerators */
#endif /* CPPCODEGENERATOR_H_ */
