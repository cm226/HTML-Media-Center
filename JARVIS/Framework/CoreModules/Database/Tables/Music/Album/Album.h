/*
 * Album.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include "DatabaseTable.h"
#include "Fields/AlbumName.h"
#include "Fields/ArtistName.h"

namespace DatabaseTables {

class Album: public DatabaseTables::DatabaseTable {
public:
	Album();
	virtual ~Album();

	AlbumName* albumname;
	ArtistName* artist;
};

} /* namespace DatabaseTables */
#endif /* ALBUM_H_ */
