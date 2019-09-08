/*
 * AbstractClass.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef ABSTRACTCLASS_H_
#define ABSTRACTCLASS_H_

#include <string>
#include <vector>
#include <list>
#include "Member.h"
#include "Method.h"
#include "../Dependancy.h"


namespace CodeGenerators {

class GenericClass {

private:
	std::string postClassModStr;
	std::string preClassModString;

	Member baseClass;
	bool baseClassValid;

public:
	GenericClass(const std::string* name);

	virtual ~GenericClass();

public:
	std::string name;
	std::vector<std::string> namespaces;
	std::list<Dependancy> dependanceys;

	Method* getConstructor();
	Method* getDeConstructor();

	std::vector<Member> publicPropertys;
	std::vector<Member> privatePropertys;
	std::vector<Member> protectedPropertys;
	
	std::vector<Method> publicMethods;
	std::vector<Method> privateMethods;
	std::vector<Method> protectedMethods;

	void addBaseClass(Member& base);
	bool getBaseClass(Member& baseClass);

	void setPostClassModifierString(std::string postClassMod);
	void setPreClassModString(std::string preClassModStr);

	bool getPostClassModifierString(std::string&);
	bool getPreClassModifierString(std::string&);

};

} /* namespace CodeGenerators */
#endif /* ABSTRACTCLASS_H_ */
