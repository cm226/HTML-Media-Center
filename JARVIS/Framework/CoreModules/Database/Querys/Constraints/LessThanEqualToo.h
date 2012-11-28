/*
 * LessThanEqualToo.h
 *
 *  Created on: Nov 25, 2012
 *      Author: craig
 */

#ifndef LESSTHANEQUALTOO_H_
#define LESSTHANEQUALTOO_H_

#include "Constraint.h"

namespace DatabaseTables {

class LessThanEqualToo: public DatabaseTables::Constraint {
public:
	LessThanEqualToo(IDatabaseTableField* field, std::string value);
	virtual ~LessThanEqualToo();
};

} /* namespace DatabaseTables */
#endif /* LESSTHANEQUALTOO_H_ */
