/*
 * AlbumName.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "AlbumName.h"

namespace DatabaseTables {

AlbumName::AlbumName() :DatabaseTables::DatabaseTableField<std::string>("Album") {
	// TODO Auto-generated constructor stub

}

AlbumName::~AlbumName() {
	// TODO Auto-generated destructor stub
}

std::string AlbumName::getName()
{
	return "Album.Name";

}

} /* namespace DatabaseTables */
