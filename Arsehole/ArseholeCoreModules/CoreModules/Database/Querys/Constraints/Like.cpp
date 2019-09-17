#include "Like.h"

namespace DatabaseTables{


	Like::Like(IDatabaseTableField* field, std::string value)  :DatabaseTables::Constraint(field,value)
	{
	}
	Like::Like(IDatabaseTableField* field, IDatabaseTableField* field2) : DatabaseTables::Constraint(field,field2)
	{
	}
	Like::~Like()
	{
	}

	std::string Like::getQuerystring()
	{
		if(this->field2 == NULL)
			return this->field->getName()+" LIKE '"+this->value+"'";
		else
			return this->field->getName()+" LIKE "+this->field2->getName();
	}
}