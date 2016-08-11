/*
 * CppClass.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef CPPCLASS_H_
#define CPPCLASS_H_

#include <string>
#include <iostream>
#include <fstream>


#include "../GenericClass.h"
#include "../IClassWritter.h"

namespace CodeGenerators {

class CppClass : IClassWritter
{
private:
	GenericClass* gclass;

	void writeMethod(Method* meth, std::ofstream* fs);

public:
	CppClass(GenericClass* toWrite);
	virtual ~CppClass();

	void write(std::string* dir);

};

} /* namespace CodeGenerators */
#endif /* CPPCLASS_H_ */
