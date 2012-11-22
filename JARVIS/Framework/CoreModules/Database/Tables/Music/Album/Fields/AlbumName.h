/*
 * AlbumName.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef ALBUMNAME_H_
#define ALBUMNAME_H_

#include "DatabaseTableField.h"

namespace DatabaseTables {

class AlbumName: public DatabaseTables::DatabaseTableField {
public:
	AlbumName();
	virtual ~AlbumName();
};

} /* namespace DatabaseTables */
#endif /* ALBUMNAME_H_ */
