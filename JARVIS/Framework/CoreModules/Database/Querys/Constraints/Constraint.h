/*
 * Constraint.h
 *
 *  Created on: Nov 24, 2012
 *      Author: craig
 */

#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_
#include "../../Tables/DatabaseTableField.h"
#include <string>

namespace DatabaseTables {



class Constraint {
public:
	IDatabaseTableField* field;
	std::string value;


	Constraint(IDatabaseTableField* field, std::string value)
	{
		this->field = field;
		this->value = value;
	};
	virtual ~Constraint(){};

	virtual void getQuerystring(std::string* query) = 0;

};

} /* namespace DatabaseTables */
#endif /* CONSTRAINT_H_ */
