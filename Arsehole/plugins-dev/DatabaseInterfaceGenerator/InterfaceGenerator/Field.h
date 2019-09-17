/*
 * Field.h
 *
 *  Created on: 2 Jan 2013
 *      Author: craig
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <string>

class Field {
public:
	enum sqlFieldType {INT, VARCHAR, DATE, TIME,UNKNOWN};

private:
	std::string fieldName;
	sqlFieldType varName;

public:

	Field(std::string fieldName, sqlFieldType varName)
	{
		this->fieldName = fieldName;
		this->varName = varName;
	}
	virtual ~Field();

	std::string FieldName(){return this->fieldName;};
	sqlFieldType VarName(){return this->varName;};
};

#endif /* FIELD_H_ */
