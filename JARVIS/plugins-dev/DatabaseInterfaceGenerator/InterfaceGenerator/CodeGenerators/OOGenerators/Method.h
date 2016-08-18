#ifndef _METHODH_
#define _METHODH_

#include <string>
#include <vector>
#include "../ITypeToString.h"

namespace CodeGenerators {

class Method
{
public:
	struct typeName 
	{
		Types t;
		std::string name;
	};

private: 
	std::vector<typeName> args;
	Types returnType;
	std::string content;
	std::string name;

public:

	Method(std::string name);
	virtual ~Method(void);


	void setReturnType(Types t);
	void addArgs(Types t, std::string name);
	void setContent(std::string content);

	void getReturnType(Types* t);
	void getArgs(std::vector<typeName>* args);
	void getContent(std::string* content);
	void getMethodName(std::string* name);
};

}
#endif
