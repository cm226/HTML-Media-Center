#ifndef _MEMBERH_
#define _MEMBERH_

#include <string>
#include <list>
#include "../ITypeToString.h"

namespace CodeGenerators {
class Member
{
private:
	Types genericsType;

public:
	Types returnT;
	std::string name;
	std::list<std::string> ctorArgs;

	Member(){};

	Member(Types returnT, std::string name);
	void setGenericType(Types gnericsType);
	Types getGenericType();

	virtual ~Member(void);




};
}
#endif

