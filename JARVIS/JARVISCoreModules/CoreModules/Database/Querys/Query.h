/*
 * Query.h
 *
 *  Created on: Nov 24, 2012
 *      Author: craig
 */

#ifndef QUERY_H_
#define QUERY_H_

#include <vector>

#include "IQuery.h"
#include "Constraints/Constraints.h"
#include "Descriptor/Limit.h"
#include "../Tables/DatabaseTableField.h"
#include "../Tables/DatabaseTable.h"
#include "../ResultWrapper.h"
#include "../../exportMacros.h"

namespace DatabaseTables {

class DLLCORE_API Query : public IQuery {
private:
	ResultWrapper* result;
	std::vector<IDatabaseTableField*>* fields;
	std::vector<IConstraint*>* constraints;
	std::vector<Descriptors::Descriptor*>* descriptors;


public:
	Query();
	virtual ~Query();

	void addSelectItem(IDatabaseTableField* field);
	void addSelectItem(DatabaseTable* table);

	void addConstraint(IConstraint* con);
	void addDescriptor(Descriptors::Descriptor* desk);


	std::string buildQuery();
	void listSelectedFields(IDatabaseTableField** fields, int* numOfFeilds);
	void setQueryResult(ResultWrapper* result);
	bool nextLine();

};

} /* namespace DatabaseTables */
#endif /* QUERY_H_ */
