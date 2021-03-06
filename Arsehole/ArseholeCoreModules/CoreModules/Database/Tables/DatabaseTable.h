/*
 * DatabaseTable.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef DATABASETABLE_H_
#define DATABASETABLE_H_

#include <string>
#include <vector>
#include "IDatabaseTableField.h"
#include "../../exportMacros.h"

namespace DatabaseTables {

class DLLCORE_API DatabaseTable {

public:
	DatabaseTable();
	virtual ~DatabaseTable();

	virtual std::string getInsertQuery() =0 ;
	virtual std::string getUpdateQuery() = 0;

	virtual void getFields(std::vector<IDatabaseTableField*>* fields) = 0;
	virtual IDatabaseTableField* getPrimaryKey(){return NULL;};

	virtual std::string tableName() = 0;
};

} /* namespace DatabaseTables */
#endif /* DATABASETABLE_H_ */
