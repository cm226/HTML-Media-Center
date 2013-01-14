/*
 * Query.h
 *
 *  Created on: Nov 24, 2012
 *      Author: craig
 */

#ifndef QUERY_H_
#define QUERY_H_

#include <vector>

#include "Constraints/Constraints.h"
#include "../Tables/DatabaseTableField.h"
#include "../Tables/DatabaseTable.h"
#include "../ResultWrapper.h"

namespace DatabaseTables {

class Query {
private:
	ResultWrapper* result;
	std::vector<IDatabaseTableField*>* fields;
	std::vector<IConstraint*>* constraints;


public:
	Query();
	virtual ~Query();

	void addSelectItem(IDatabaseTableField* field);
	void addSelectItem(DatabaseTable* table);

	void addConstraint(IConstraint* con);


	std::string buildQuery();
	void listSelectedFields(IDatabaseTableField** fields, int* numOfFeilds);
	void setQueryResult(ResultWrapper* result);
	bool nextLine();

};

} /* namespace DatabaseTables */
#endif /* QUERY_H_ */
