/*
 * CppClass.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef CPPHEADER_H_
#define CPPHEADER_H_

#include <string>

#include "../GenericClass.h"
#include "../IClassWritter.h"

namespace CodeGenerators {

class CppHeader : IClassWritter
{
private:
	GenericClass* gclass;

public:
	CppHeader(GenericClass* toWrite);
	virtual ~CppHeader();

	void write(std::string* dir);

private:

	void writeDependanceys(std::ofstream* file);
	void writeMembers(std::ofstream* file,std::string accessMods[3],ItypeToString& typeToStr);
	void writeMethods(std::ofstream* file,std::string accessMods[3],ItypeToString& typeToStr);
	void writeArgs(std::ofstream* file,Method* method,ItypeToString& typeToStr);

};

} /* namespace CodeGenerators */
#endif /* CPPCLASS_H_ */
