/*
 * DatabaseTable.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef DATABASETABLE_H_
#define DATABASETABLE_H_

#include <String>

namespace DatabaseTables {

class DatabaseTable {
public:
	DatabaseTable();
	virtual ~DatabaseTable();

	virtual std::string getInsertQuery() =0 ;
};

} /* namespace DatabaseTables */
#endif /* DATABASETABLE_H_ */
