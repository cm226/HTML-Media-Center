#include "Limit.h"

namespace DatabaseTables
{

namespace Descriptors
{


Limit::Limit(std::string limit) : Descriptor(), limit(limit)
{

}


Limit::~Limit(void)
{
}

std::string Limit::getString()
{
	return "LIMIT "+this->limit;
}

}
}