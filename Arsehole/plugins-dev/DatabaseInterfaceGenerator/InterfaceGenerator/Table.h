/*
 * Table.h
 *
 *  Created on: 2 Jan 2013
 *      Author: craig
 */

#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include <vector>

#include "Field.h"

class Table {
public:
	std::string tableName;
	Field primaryKey;
	std::vector<Field> fields;

	Table();
	virtual ~Table();
};

#endif /* TABLE_H_ */
