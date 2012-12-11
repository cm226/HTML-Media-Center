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

Equals::~Equals() {
	// TODO Auto-generated destructor stub
}

void Equals::getQuerystring(std::string* query)
{
	*query = this->field->getName()+"="+this->value;
}

} /* namespace DatabaseTables */
