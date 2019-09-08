#include "Method.h"

namespace CodeGenerators {

Method::Method(std::string name)
{
	this->returnType = Types("UNKNOWN");
	this->name = name;
}


Method::~Method(void)
{
}

void Method::setReturnType(Types t)
{
	this->returnType = t;
}
void Method::addArgs(Types t, std::string name)
{
	typeName tn;
	tn.name = name;
	tn.t = t;
	this->args.push_back(tn);
}
void Method::setContent(std::string content)
{
	this->content = content;
}

void Method::getReturnType(Types* t)
{
	*t = this->returnType;
}
void Method::getArgs(std::vector<typeName>* args)
{
	*args = this->args;
}
void Method::getContent(std::string* content)
{
	*content = this->content;
}

void Method::getMethodName(std::string* name)
{
	*name = this->name;
}

}
