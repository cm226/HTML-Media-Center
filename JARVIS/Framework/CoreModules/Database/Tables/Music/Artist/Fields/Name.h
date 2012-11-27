/*
 * Name.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef NAME_H_
#define NAME_H_

#include "DatabaseTableField.h"

namespace DatabaseTables {

class Name: public DatabaseTables::DatabaseTableField {
public:
	Name();
	virtual ~Name();
};

} /* namespace DatabaseTables */
#endif /* NAME_H_ */
