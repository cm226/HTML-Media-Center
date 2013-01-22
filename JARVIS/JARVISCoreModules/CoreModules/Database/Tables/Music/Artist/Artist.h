/*
 * Artist.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef ARTIST_H_
#define ARTIST_H_

#include "../../DatabaseTable.h"

#include "Fields/Name.h"

namespace DatabaseTables {

class Artist: public DatabaseTables::DatabaseTable {
public:
	Artist();
	virtual ~Artist();

	Name* name;

};

} /* namespace DatabaseTables */
#endif /* ARTIST_H_ */
