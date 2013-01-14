/*
 * LessThan.h
 *
 *  Created on: Nov 25, 2012
 *      Author: craig
 */

#ifndef LESSTHAN_H_
#define LESSTHAN_H_

#include "Constraint.h"

namespace DatabaseTables {

class LessThan: public Constraint {
public:
	LessThan(IDatabaseTableField* field, std::string value);
	virtual ~LessThan();
};

} /* namespace DatabaseTables */
#endif /* LESSTHAN_H_ */
