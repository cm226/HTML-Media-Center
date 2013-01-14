/*
 * GreaterThan.h
 *
 *  Created on: Nov 25, 2012
 *      Author: craig
 */

#ifndef GREATERTHAN_H_
#define GREATERTHAN_H_

#include "Constraint.h"

namespace DatabaseTables {

class GreaterThan: public Constraint {
public:
	GreaterThan(IDatabaseTableField* field, std::string value);
	virtual ~GreaterThan();
};

} /* namespace DatabaseTables */
#endif /* GREATERTHAN_H_ */
