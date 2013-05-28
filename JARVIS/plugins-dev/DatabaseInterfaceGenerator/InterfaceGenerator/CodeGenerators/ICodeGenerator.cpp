/*
 * ICodeGenerator.cpp
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#include "ICodeGenerator.h"


#include "OOGenerators/GenericClass.h"
#include "OOGenerators/C++/CppCodeGenerator.h"


namespace CodeGenerators {

ICodeGenerator::ICodeGenerator(std::string fileName) 
{
	this->fileName = fileName;
}

ICodeGenerator::~ICodeGenerator() {
	// TODO Auto-generated destructor stub
}

} /* namespace CodeGenerators */


/*
dummy entry while this isent a dll
*/
/*
int main (int argc, char** args)
{
	CodeGenerators::Method add1("add1");
	CodeGenerators::Member member1(CodeGenerators::Types::DOUBLE, "member");
	std::string temp;

	std::vector<CodeGenerators::Method::typeName*> add1Args;
	
	CodeGenerators::Method::typeName arg1;
	arg1.name = "i2";
	arg1.t = CodeGenerators::Types::INT;
	add1Args.push_back(&arg1);

	CodeGenerators::Method::typeName arg2;
	arg2.name = "i3";
	arg2.t = CodeGenerators::Types::INT;
	add1Args.push_back(&arg2);

	temp = "int i = 0; \n i++;";
	add1.setContent(&temp);
	add1.addArgs(&add1Args);
	add1.setReturnType(CodeGenerators::Types::INT);
	temp = "TestClass";
	CodeGenerators::GenericClass gc(&temp);
	gc.privateMethods.push_back(add1);
	gc.privateMethods.push_back(add1);
	gc.privateMethods.push_back(add1);

	gc.publicMethods.push_back(add1);
	gc.publicMethods.push_back(add1);

	gc.protectedMethods.push_back(add1);

	gc.publicPropertys.push_back(member1);
	gc.publicPropertys.push_back(member1);
	gc.publicPropertys.push_back(member1);

	gc.protectedPropertys.push_back(member1);
	gc.protectedPropertys.push_back(member1);

	gc.privatePropertys.push_back(member1);

	gc.nameSpace = "MaNamespace";

	CodeGenerators::CppCodeGenerator cppGenerator("D:\\programming\\CodeGeneration\\CodeGeneration\\");

	cppGenerator.addClass(&gc);
	cppGenerator.save();
	

	return 0;
}*/
