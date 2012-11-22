/*
 * Album.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include "DatabaseTable.h"

namespace DatabaseTables {

class Album: public DatabaseTables::DatabaseTable {
public:
	Album();
	virtual ~Album();
};

} /* namespace DatabaseTables */
#endif /* ALBUM_H_ */
