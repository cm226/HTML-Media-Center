/*
 * AlbumName.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef ALBUMNAME_H_
#define ALBUMNAME_H_

#include "../../../DatabaseTableField.h"
#include <string>

namespace DatabaseTables {

class AlbumName: public DatabaseTables::DatabaseTableField<std::string> {

public:
	AlbumName();
	virtual ~AlbumName();
	virtual std::string getName();

	void takeValue(ResultWrapper* resRwapper){};
	std::string fieldName(){ return "";};
};

} /* namespace DatabaseTables */
#endif /* ALBUMNAME_H_ */
