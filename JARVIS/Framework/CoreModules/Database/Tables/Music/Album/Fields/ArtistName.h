/*
 * ArtistName.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef ARTISTNAME_H_
#define ARTISTNAME_H_

#include "DatabaseTableField.h"
#include "string"

namespace DatabaseTables {

class ArtistName: public DatabaseTables::DatabaseTableField<std::string> {
public:
	ArtistName();
	virtual ~ArtistName();
};

} /* namespace DatabaseTables */
#endif /* ARTISTNAME_H_ */
