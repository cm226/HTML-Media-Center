/*
 * Name.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef NAME_H_
#define NAME_H_

#include "../../../DatabaseTableField.h"
#include "string"

namespace DatabaseTables {

class Name: public DatabaseTables::DatabaseTableField<std::string> {
public:
	Name();
	virtual ~Name();
	virtual std::string getName();

	void takeValue(ResultWrapper* resRwapper){};
	std::string fieldName(){return "";};
};

} /* namespace DatabaseTables */
#endif /* NAME_H_ */
