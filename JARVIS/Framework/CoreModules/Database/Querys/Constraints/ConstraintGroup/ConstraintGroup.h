#ifndef _CONSTRAINT_GROUP_
#define _CONSTRAINT_GROUP_

#include <string>
#include <vector>
#include "../Constraint.h"

namespace DatabaseTables {
namespace Constraints
{
	namespace Groups
	{

		class ConstraintGroup :public  IConstraint
		{

protected:
	std::vector<IConstraint*> constrints;

public:
	ConstraintGroup();
	virtual ~ConstraintGroup();

	void addConstrint(DatabaseTables::Constraint* constraint);

	virtual std::string getQuerystring() = 0;
	virtual void getTableNames(std::vector<std::string>* tables);


		};
	}
}
}


#endif