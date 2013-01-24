/*
 * DatabaseTableField.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef DATABASETABLEFIELD_H_
#define DATABASETABLEFIELD_H_

#include "IDatabaseTableField.h"
#include "DatabaseTable.h"

namespace DatabaseTables {

template <class Type> class DatabaseTableField : public IDatabaseTableField{

private:
	
	Type value;

protected:
	DatabaseTable* owner;
	std::string ownerNameStr;
	std::string getName() {return this->ownerName()+"."+this->fieldName(); };

public:
	DatabaseTableField(DatabaseTable* owner)
	{
		this->owner = owner;
	};
	DatabaseTableField(std::string OwnerName)
	{
		this->ownerNameStr = OwnerName;
		this->owner = NULL;
	};

	virtual ~DatabaseTableField(){};

	void setValue(Type* newValue)
	{
		this->value = *newValue;
	}
	Type getValue()
	{
		return this->value;
	}

	std::string ownerName()	
	{
		if(this->owner != NULL)
			return this->owner->tableName();
		else
			return this->ownerNameStr;
	}

	virtual void takeValue(ResultWrapper* resRwapper) = 0;

};

} /* namespace DatabaseTables */
#endif /* DATABASETABLEFIELD_H_ */

