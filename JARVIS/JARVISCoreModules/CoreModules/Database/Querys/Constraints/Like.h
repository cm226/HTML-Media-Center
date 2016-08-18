#ifndef LIKE_H_
#define LIKE_H_

#include "Constraint.h"

namespace DatabaseTables {



class Like : public DatabaseTables::Constraint {


public:
	Like(IDatabaseTableField* field, std::string value);
	Like(IDatabaseTableField* field, IDatabaseTableField* field2);
	virtual ~Like();

	virtual std::string getQuerystring();

};



}

#endif