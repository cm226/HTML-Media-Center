/*
 * Song.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "Song.h"

namespace DatabaseTables {

Song::Song() {
	this->songname = new SongName();
	this->songURL = new SongURL();

}

Song::~Song() {
	delete this->songname;
	delete this->songURL;
}

} /* namespace DatabaseTables */
