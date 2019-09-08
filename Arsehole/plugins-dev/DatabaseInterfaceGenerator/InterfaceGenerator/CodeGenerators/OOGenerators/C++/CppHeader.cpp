/*
 * CppClass.cpp
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#include "CppHeader.h"
#include "CppTypeToString.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include "../Exceptions/InvalidArgumanentException.h"


namespace CodeGenerators {

CppHeader::CppHeader(GenericClass* toWrite){
	
	this->gclass= toWrite;
}

CppHeader::~CppHeader() {
	// TODO Auto-generated destructor stub
}


void CppHeader::write(std::string* dir)
{
	if(dir == NULL || this->gclass == NULL)
		throw argumentExeption();

	ItypeToString& typeToStr = CppTypeToString::getInstance();
	std::string accessMods[3]  = {"private:","public:", "protected:"};
	std::stringstream tempFileStream;
	std::string headerFileName = "";
		headerFileName +=(*dir);


	bool usingNamespace = this->gclass->namespaces.size()> 0;
	if(usingNamespace)
		{
			std::vector<std::string>::iterator namespaceIt;
			std::vector<std::string>::iterator end = this->gclass->namespaces.end();
			std::vector<std::string>::iterator begin = this->gclass->namespaces.begin();
			for(namespaceIt = begin; namespaceIt != end; namespaceIt++)
			{
				tempFileStream << "namespace " << *namespaceIt << "{ " << std::endl;
				headerFileName += *namespaceIt+"/";
			}
		}
	bool dirCreated = boost::filesystem::create_directories(headerFileName);
			if(!dirCreated)
				std::cerr << "error Directory Not Created" << std::endl;

	headerFileName +=this->gclass->name;
	headerFileName +=".h";
	std::ofstream headerFile (headerFileName);
	std::string tmpString;

	std::vector<std::string>::iterator namespacesIt= this->gclass->namespaces.begin();
	for(; namespacesIt != this->gclass->namespaces.end(); namespacesIt++)
		tmpString += boost::to_upper_copy(*namespacesIt)+"_";

	tmpString += boost::to_upper_copy(this->gclass->name);

	headerFile << "#ifndef _" << tmpString << "_ " << std::endl;
	headerFile << "#define _" << tmpString << "_" << std::endl;
	this->writeDependanceys(&headerFile);
	headerFile << tempFileStream.str();

	std::string preClassMod;
	std::string postClassMod;
	bool usingPostClassMod =this->gclass->getPostClassModifierString(postClassMod);
	bool usingPreClassMod =this->gclass->getPreClassModifierString(preClassMod);

	if(usingPreClassMod)
		headerFile << preClassMod<< " ";
	headerFile << "class ";
	if(usingPostClassMod)
		headerFile << postClassMod << " ";
	headerFile << this->gclass->name;

	Member baseClass;
	this->gclass->getBaseClass(baseClass);


	if(baseClass.name.compare("") != 0)
		headerFile << " : public " << baseClass.name;
	if(baseClass.getGenericType().t != Types::UNSPECIFIED)
	{
		std::string genericType;
		typeToStr.convertType(baseClass.getGenericType(), &genericType);
		headerFile << "<" << genericType << ">";
	}

	headerFile << "{ " << std::endl;

	this->writeMembers(&headerFile,accessMods,typeToStr);
	this->writeMethods(&headerFile,accessMods,typeToStr);

	headerFile << "}; "<<std::endl;

	if(usingNamespace)
		{
			for(unsigned int i = 0 ; i < this->gclass->namespaces.size(); i++)
				headerFile << "}" << std::endl;
		}

	headerFile <<" #endif";
	headerFile.flush();
	headerFile.close();
}

void CppHeader::writeDependanceys(std::ofstream* file)
{
	std::list<Dependancy>::iterator dependancyIt;
	for(dependancyIt = this->gclass->dependanceys.begin(); dependancyIt != this->gclass->dependanceys.end(); dependancyIt++)
	{
		Dependancy dep = *dependancyIt;
		if(dep.getStandardLibraryDependancy().compare("") != 0)
			*file << "#include <" << dep.getStandardLibraryDependancy()<< ">"<< std::endl;
		else
		*file << "#include \"" << dep.getPathToDependancy() << "\""<< std::endl;
	}

}

void CppHeader::writeMembers(std::ofstream* headerFile,std::string accessMods[3],ItypeToString& typeToStr)
{
	std::vector<Member>::iterator memberIt;
	std::vector<Member>* memberArr[3] = {&this->gclass->privatePropertys, &this->gclass->publicPropertys, &this->gclass->protectedPropertys };
	std::string tmpString, genericTypeStr;

	*headerFile << "//Member Variables" <<std::endl;
	// member variables
	for(int i =0; i < 3; i ++)
	{
		*headerFile << accessMods[i] << std::endl;
		for(memberIt = memberArr[i]->begin(); memberIt !=  memberArr[i]->end(); memberIt++)
		{
			typeToStr.convertType((*memberIt).returnT, &tmpString);
			*headerFile << tmpString << " " << (*memberIt).name;
			if((*memberIt).getGenericType().t != Types::UNSPECIFIED)
			{
				typeToStr.convertType((*memberIt).getGenericType(), &genericTypeStr);
				*headerFile << "<" << genericTypeStr << ">";
			}

			*headerFile << ";"<<std::endl;
		}
	}
}

void CppHeader::writeMethods(std::ofstream* headerFile,std::string accessMods[3],ItypeToString& typeToStr)
{
	std::vector<Method>* methodArr[3] = {&this->gclass->privateMethods, &this->gclass->publicMethods, &this->gclass->protectedMethods };
	std::vector<Method>::iterator methodIt;
	std::string tmpString;
	std::string tmpStr2;


	*headerFile << "//Methods" <<std::endl;
		Types returnT;
		// methods
		for(int i =0; i < 3; i ++)
		{
			*headerFile << accessMods[i] << std::endl;
			for(methodIt = methodArr[i]->begin(); methodIt !=  methodArr[i]->end(); methodIt++)
			{
				(*methodIt).getReturnType(&returnT);
				typeToStr.convertType(returnT, &tmpString);

				(*methodIt).getMethodName(&tmpStr2);
				*headerFile << tmpString << " " << tmpStr2 << "(";

				this->writeArgs(headerFile,&(*methodIt),typeToStr);

				*headerFile << ");"<< std::endl;
				}
		}
}

void CppHeader::writeArgs(std::ofstream* headerFile,Method* method,ItypeToString& typeToStr)
{
	std::vector<Method::typeName> args;
	std::vector<Method::typeName>::iterator argsIt;
	std::string tmpString;

	//args
	method->getArgs(&args);
	for(argsIt = args.begin(); argsIt != args.end(); argsIt++)
	{
		typeToStr.convertType((*argsIt).t,&tmpString);
		*headerFile << tmpString <<" "<< (*argsIt).name;

		if(argsIt != --args.end())
			*headerFile << ",";
	}
}

} /* namespace CodeGenerators */
