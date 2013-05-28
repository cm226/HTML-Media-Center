#include "CppTypeToString.h"
#include "../Exceptions/InvalidArgumanentException.h"

namespace CodeGenerators {


	void CppTypeToString::convertType(Types t, std::string* out)
	{
		if(t.type != "")
		{
			 *out = t.type;
			 return;
		}

		switch(t.t)
		{
		case(Types::DOUBLE):
			*out = "double";
			break;
		case(Types::FLOAT):
		*out = "float";
		break;
		case(Types::INT):
		*out = "int";
		break;
		case(Types::STRING):
		*out = "std::string";
		break;
		case(Types::VOID):
		*out = "void";
		break;
		default:
			throw argumentExeption();
		}
	}


}
