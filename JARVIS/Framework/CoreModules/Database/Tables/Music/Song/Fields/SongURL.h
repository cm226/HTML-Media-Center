/*
 * SongURL.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef SONGURL_H_
#define SONGURL_H_

#include "DatabaseTableField.h"

namespace DatabaseTables {

class SongURL: public DatabaseTables::DatabaseTableField {
public:
	SongURL();
	virtual ~SongURL();
};

} /* namespace DatabaseTables */
#endif /* SONGURL_H_ */
