/*
 * CppTypeToString.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef CPPTYPETOSTRING_H_
#define CPPTYPETOSTRING_H_

#include <string>
#include "../../ITypeToString.h"

namespace CodeGenerators {

class CppTypeToString : public ItypeToString
{
private:
	CppTypeToString(){};
	virtual ~CppTypeToString(){};
	CppTypeToString(CppTypeToString const&);
	void operator=(CppTypeToString const&);

public:

	virtual void convertType(Types t, std::string* out);
	 static CppTypeToString& getInstance()
        {
            static CppTypeToString instance;
            return instance;
        }
};

} /* namespace CodeGenerators */
#endif /* CPPCLASS_H_ */
