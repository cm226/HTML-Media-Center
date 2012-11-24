/*
 * DatabaseTableField.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef DATABASETABLEFIELD_H_
#define DATABASETABLEFIELD_H_

namespace DatabaseTables {

template <class Type> class DatabaseTableField {

private:
	Type value;

public:
	DatabaseTableField();
	virtual ~DatabaseTableField();

	void setValue(Type newValue)
	{
		this->value = value;
	}
};

} /* namespace DatabaseTables */
#endif /* DATABASETABLEFIELD_H_ */
