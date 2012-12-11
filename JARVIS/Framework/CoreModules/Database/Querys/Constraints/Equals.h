/*
 * Equals.h
 *
 *  Created on: Nov 25, 2012
 *      Author: craig
 */

#ifndef EQUALS_H_
#define EQUALS_H_

#include "Constraint.h"

namespace DatabaseTables {

class Equals: public DatabaseTables::Constraint {
public:
	Equals(IDatabaseTableField* field, std::string value);
	virtual ~Equals();

	virtual void getQuerystring(std::string* query);
};

} /* namespace DatabaseTables */
#endif /* EQUALS_H_ */
