/*
 * Query.h
 *
 *  Created on: Nov 24, 2012
 *      Author: craig
 */

#ifndef QUERY_H_
#define QUERY_H_

#include "Constraints/Constraints.h"
#include "../Tables/DatabaseTableField.h"
#include "../Tables/DatabaseTable.h"

namespace DatabaseTables {

class Query {
public:
	Query();
	virtual ~Query();

	void addSelectItem(DatabaseTableField* field);
	void addSelectItem(DatabaseTable* table);

	void addConstraint(Constraint* con);

	std::string buildQuery();


};

} /* namespace DatabaseTables */
#endif /* QUERY_H_ */
