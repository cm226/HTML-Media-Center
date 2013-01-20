/*
 * SongName.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef SONGNAME_H_
#define SONGNAME_H_

#include "../../../DatabaseTableField.h"
#include <string>

namespace DatabaseTables {

class SongName: public DatabaseTables::DatabaseTableField<std::string> {
public:
	SongName();
	virtual ~SongName();
	virtual std::string getName();

	void takeValue(ResultWrapper* resRwapper){};
	std::string fieldName(){return "";};
};

} /* namespace DatabaseTables */
#endif /* SONGNAME_H_ */
