/*
 * Constraint.h
 *
 *  Created on: Nov 24, 2012
 *      Author: craig
 */

#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_
#include "../../Tables/DatabaseTableField.h"
#include "../../../exportMacros.h"
#include <string>
#include <vector>

namespace DatabaseTables {

class DLLCORE_API IConstraint
{
public:
	virtual std::string getQuerystring() = 0;
	virtual void getTableNames(std::vector<std::string>* tables) = 0;
};



class DLLCORE_API Constraint : public IConstraint {
protected:
	IDatabaseTableField* field;
	IDatabaseTableField* field2;

	#pragma warning( disable : 4251)
	std::string value;
	#pragma warning( default : 4251)

public:
	Constraint(IDatabaseTableField* field, std::string value)
	{
		this->field2 = NULL;
		this->field = field;
		this->value = value;
	};

	Constraint(IDatabaseTableField* field, IDatabaseTableField* field2)
	{
		this->field = field;
		this->field2 = field2;
	};
	virtual ~Constraint(){};

	virtual std::string getQuerystring() = 0;

	void getTableNames(std::vector<std::string>* tables)
	{
		tables->push_back(this->field->ownerName());

		if(this->field2 != NULL)
			tables->push_back(this->field2->ownerName());
	}

};

} /* namespace DatabaseTables */
#endif /* CONSTRAINT_H_ */
