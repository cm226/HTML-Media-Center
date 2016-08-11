/*
 * AbstractClass.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef ABSTRACTCLASS_H_
#define ABSTRACTCLASS_H_

#include <string>

namespace CodeGenerators {

class AbstractClass {
private:
	std::string name;
public:
	enum varTypes {INT, STRING, FLOAT, DOUBLE};

public:
	AbstractClass(const std::string* name);
	virtual ~AbstractClass();

	virtual void addPublicProperty(varTypes type, std::string* name, std::string* initialVal) = 0;
	virtual void addPublicProperty(varTypes type, std::string* name) = 0;

	virtual void addPrivateProperty(varTypes type, std::string* name, std::string* initialVal) = 0;
	virtual void addPrivateProperty(varTypes type, std::string* name) = 0;

	virtual void addPublicMethod(const std::string* methodName, const std::string* methodText) = 0;
	virtual void addPrivateMethod(const std::string* methodName, const std::string* methodText) = 0;

};

} /* namespace CodeGenerators */
#endif /* ABSTRACTCLASS_H_ */
