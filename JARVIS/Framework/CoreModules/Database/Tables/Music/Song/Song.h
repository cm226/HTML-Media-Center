/*
 * Song.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef SONG_H_
#define SONG_H_

#include "../../DatabaseTable.h"
#include "Fields/SongName.h"
#include "Fields/SongURL.h"

namespace DatabaseTables {

class Song: public DatabaseTables::DatabaseTable {

public:

	SongName* songname;
	SongURL* songURL;

	Song();
	virtual ~Song();
};

} /* namespace DatabaseTables */
#endif /* SONG_H_ */
