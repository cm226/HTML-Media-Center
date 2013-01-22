/*
 * Artist.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "Artist.h"

namespace DatabaseTables {

Artist::Artist() {
	this->name = new Name();

}

Artist::~Artist() {
	delete this->name;
}

} /* namespace DatabaseTables */
