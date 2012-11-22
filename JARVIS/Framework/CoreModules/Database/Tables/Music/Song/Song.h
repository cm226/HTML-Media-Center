/*
 * Song.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef SONG_H_
#define SONG_H_

#include "DatabaseTable.h"

namespace DatabaseTables {

class Song: public DatabaseTables::DatabaseTable {
public:
	Song();
	virtual ~Song();
};

} /* namespace DatabaseTables */
#endif /* SONG_H_ */
