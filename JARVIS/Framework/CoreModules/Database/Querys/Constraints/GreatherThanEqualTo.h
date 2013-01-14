/*
 * GreatherThanEqualTo.h
 *
 *  Created on: Nov 25, 2012
 *      Author: craig
 */

#ifndef GREATHERTHANEQUALTO_H_
#define GREATHERTHANEQUALTO_H_

#include "Constraint.h"

namespace DatabaseTables {

class GreatherThanEqualTo: public Constraint {
public:
	GreatherThanEqualTo(IDatabaseTableField* field, std::string value);
	virtual ~GreatherThanEqualTo();
};

} /* namespace DatabaseTables */
#endif /* GREATHERTHANEQUALTO_H_ */
