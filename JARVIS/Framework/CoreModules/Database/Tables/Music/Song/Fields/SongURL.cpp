/*
 * SongURL.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "SongURL.h"

namespace DatabaseTables {

SongURL::SongURL() :  DatabaseTables::DatabaseTableField<std::string>("Song") {
	// TODO Auto-generated constructor stub

}

SongURL::~SongURL() {
	// TODO Auto-generated destructor stub
}

std::string SongURL::getName()
{
	return "Song.URL";
}

} /* namespace DatabaseTables */
