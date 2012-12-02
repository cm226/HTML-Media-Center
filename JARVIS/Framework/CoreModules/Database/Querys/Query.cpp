/*
 * Query.cpp
 *
 *  Created on: Nov 24, 2012
 *      Author: craig
 */

#include "Query.h"

namespace DatabaseTables {

Query::Query() {
	// TODO Auto-generated constructor stub

}

Query::~Query() {
	// TODO Auto-generated destructor stub
}

void Query::addConstraint(Constraint* con)
{

}

void Query::addSelectItem(IDatabaseTableField* field)
{

}
void Query::addSelectItem(DatabaseTable* table)
{

}
std::string Query::buildQuery()
{
	return "";

}

} /* namespace DatabaseTables */

