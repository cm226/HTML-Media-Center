/*
 * Album.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "Album.h"

namespace DatabaseTables {

Album::Album() {
	this->albumname = new AlbumName();
	this->artist = new ArtistName();

}

Album::~Album() {
	delete this->albumname;
	delete this->artist;
}

} /* namespace DatabaseTables */
