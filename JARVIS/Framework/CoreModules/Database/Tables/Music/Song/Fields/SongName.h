/*
 * SongName.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef SONGNAME_H_
#define SONGNAME_H_

#include "DatabaseTableField.h"

namespace DatabaseTables {

class SongName: public DatabaseTables::DatabaseTableField {
public:
	SongName();
	virtual ~SongName();
};

} /* namespace DatabaseTables */
#endif /* SONGNAME_H_ */
