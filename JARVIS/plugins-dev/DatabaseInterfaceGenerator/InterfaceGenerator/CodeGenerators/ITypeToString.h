/*
 * ITypeToString.h
 *
 *  Created on: 6 Jan 2013
 *      Author: craig
 */

#ifndef ITYPETOSTRING_H_
#define ITYPETOSTRING_H_

#include <string>

namespace CodeGenerators {


class Types
{
public:
	typedef int TYPE;
public:
	TYPE t;
	std::string type;

public:;
	Types(std::string type){this->type = type;};
	Types(TYPE type){this->t = type;};
	Types(){};

	static const TYPE UNSPECIFIED = -1;
	static const TYPE FLOAT = 0;
	static const TYPE DOUBLE = 1;
	static const TYPE INT = 2;
	static const TYPE STRING = 3;
	static const TYPE VOID = 4;
	
};


class ItypeToString {

public:
	virtual ~ItypeToString(){};
	virtual void convertType(Types t, std::string* out) = 0;

};

} /* namespace CodeGenerators */
#endif /* ICODEGENERATOR_H_ */
