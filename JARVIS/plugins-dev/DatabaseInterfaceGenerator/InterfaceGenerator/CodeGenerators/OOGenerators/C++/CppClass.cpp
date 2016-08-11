/*
 * CppClass.cpp
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#include "CppClass.h"
#include "CppTypeToString.h"
#include "../Exceptions/InvalidArgumanentException.h"
#include <sstream>
#include <boost/filesystem.hpp>

namespace CodeGenerators {




CppClass::CppClass(GenericClass* toWrite){
	this->gclass = toWrite;
}

CppClass::~CppClass()
{

}


void CppClass::write(std::string* dir)
{

	if(dir == NULL || this->gclass == NULL)
		throw argumentExeption();

	std::string fileName = "";
	fileName = (*dir);

	bool hasNamespace = this->gclass->namespaces.size() > 0;
	std::stringstream tempFileStream;

	if(hasNamespace)
	{
		std::vector<std::string>::iterator namespaceIt;
		std::vector<std::string>::iterator end = this->gclass->namespaces.end();
		std::vector<std::string>::iterator begin = this->gclass->namespaces.begin();

		for(namespaceIt = begin; namespaceIt != end; namespaceIt++)
		{
			tempFileStream << "namespace " << *namespaceIt << "{ " << std::endl;
			fileName += *namespaceIt+"/";
		}
	}
	bool dirCreated = boost::filesystem::create_directories(fileName);
		if(!dirCreated)
			std::cerr << "error Directory Not Created" << std::endl;

	fileName += this->gclass->name;
	fileName += ".cpp";
	std::ofstream classFile (fileName.c_str());
	classFile << "#include \"" << this->gclass->name << ".h\" \n";
	classFile << tempFileStream.str();

	std::vector<Method>::iterator methodIt;
	for(methodIt = this->gclass->privateMethods.begin(); methodIt != this->gclass->privateMethods.end(); methodIt++)
		this->writeMethod(&(*methodIt),&classFile);
	for(methodIt = this->gclass->protectedMethods.begin(); methodIt != this->gclass->protectedMethods.end(); methodIt++)
		this->writeMethod(&(*methodIt),&classFile);
	for(methodIt = this->gclass->publicMethods.begin(); methodIt != this->gclass->publicMethods.end(); methodIt++)
		this->writeMethod(&(*methodIt),&classFile);

	if(hasNamespace)
	{
		for(unsigned int i = 0 ; i < this->gclass->namespaces.size(); i++)
		classFile << "}" << std::endl;
	}

	classFile.flush();
	classFile.close();
}

void CppClass::writeMethod(Method* meth, std::ofstream* fs)
{
		Types t("");
		std::string returnStr;
		std::string methodName;
		std::string tempArgVal;
		std::string methodContent;
		std::vector<Method::typeName> args;
		std::vector<Method::typeName>::iterator argsIt;
		CppTypeToString& typeToString = CppTypeToString::getInstance();

		meth->getReturnType(&t);
		typeToString.convertType(t,&returnStr);
		meth->getMethodName(&methodName);
		meth->getArgs(&args);


		*fs << returnStr <<" "<< this->gclass->name <<"::"<<methodName<<"(";
		for(argsIt = args.begin(); argsIt != args.end(); argsIt++)
		{
			typeToString.convertType((*argsIt).t,&tempArgVal);
			*fs << tempArgVal << " "<<(*argsIt).name;

			if(argsIt != --args.end())
				*fs << ",";
		}
		meth->getContent(&methodContent);
		*fs << ")";
		Method* ctor = this->gclass->getConstructor();
		if(meth == ctor)
		{
			Member baseClass;
			std::string memberGeneric;
			this->gclass->getBaseClass(baseClass);
			*fs << ":" << baseClass.name;
			Types generType = baseClass.getGenericType();
			if(generType.t != CodeGenerators::Types::UNSPECIFIED)
			{
				typeToString.convertType(generType,&memberGeneric);
				*fs << "<" << memberGeneric << ">";
			}

			*fs << "(";
			std::list<std::string>::iterator ctorArgsIt = baseClass.ctorArgs.begin();
			for(; ctorArgsIt != baseClass.ctorArgs.end(); ctorArgsIt++)
			{
				if(ctorArgsIt != baseClass.ctorArgs.begin())
					*fs << ",";

				*fs << *ctorArgsIt;
			}
			*fs << ")" << std::endl;
		}
		*fs << " \n {" << std::endl;
		*fs << methodContent;
		*fs << std::endl <<"}" << std::endl;
}

} /* namespace CodeGenerators */
