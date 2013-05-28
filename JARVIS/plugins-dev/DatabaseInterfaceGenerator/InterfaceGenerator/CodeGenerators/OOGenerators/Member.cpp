#include "Member.h"

namespace CodeGenerators {

Member::Member(Types returnT, std::string name)
{
	this->returnT = returnT;
	this->name = name;
	this->genericsType = Types::UNSPECIFIED;
}


Member::~Member(void)
{
}

void Member::setGenericType(Types genericType)
{
	this->genericsType = genericType;

}

Types Member::getGenericType()
{
	return this->genericsType;

}




}
