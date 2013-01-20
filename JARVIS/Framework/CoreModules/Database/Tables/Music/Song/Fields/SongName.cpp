/*
 * SongName.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "SongName.h"

namespace DatabaseTables {

SongName::SongName() : DatabaseTables::DatabaseTableField<std::string>("Song")  {
	// TODO Auto-generated constructor stub

}

SongName::~SongName() {
	// TODO Auto-generated destructor stub
}

std::string SongName::getName()
{
	return "Song.Name";
}

} /* namespace DatabaseTables */
