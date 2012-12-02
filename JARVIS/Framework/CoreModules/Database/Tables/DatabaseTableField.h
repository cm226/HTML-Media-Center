/*
 * DatabaseTableField.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef DATABASETABLEFIELD_H_
#define DATABASETABLEFIELD_H_

#include "IDatabaseTableField.h"

namespace DatabaseTables {

template <class Type> class DatabaseTableField : public IDatabaseTableField{

private:
	Type value;

public:
	DatabaseTableField(){};
	virtual ~DatabaseTableField(){};

	void setValue(IDatabaseFieldType* newValue)
	{
		this->value = (Type)value;
	}
	virtual std::string getName()=0;

};

} /* namespace DatabaseTables */
#endif /* DATABASETABLEFIELD_H_ */


