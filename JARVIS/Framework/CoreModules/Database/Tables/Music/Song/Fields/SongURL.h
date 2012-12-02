/*
 * SongURL.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef SONGURL_H_
#define SONGURL_H_

#include "../../../DatabaseTableField.h"
#include <string>

namespace DatabaseTables {

class SongURL: public DatabaseTables::DatabaseTableField<std::string> {
public:
	SongURL();
	virtual ~SongURL();

	virtual std::string getName();
};

} /* namespace DatabaseTables */
#endif /* SONGURL_H_ */
