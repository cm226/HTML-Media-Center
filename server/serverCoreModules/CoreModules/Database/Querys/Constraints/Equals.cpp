/*
 * Equals.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: craig
 */

#include "Equals.h"

namespace DatabaseTables {

Equals::Equals(IDatabaseTableField* field, std::string value): DatabaseTables::Constraint(field, value)
{


}

Equals::Equals(IDatabaseTableField* field, IDatabaseTableField* field2) : DatabaseTables::Constraint(field, field2)
{

}

Equals::~Equals() {
	// TODO Auto-generated destructor stub
}

std::string Equals::getQuerystring()
{
	if(this->field2 == NULL)
		return this->field->getName()+"='"+this->value+"'";
	else
		return this->field->getName()+"="+this->field2->getName();
}

} /* namespace DatabaseTables */
