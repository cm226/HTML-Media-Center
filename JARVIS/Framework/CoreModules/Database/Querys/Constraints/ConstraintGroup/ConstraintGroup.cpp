#include "ConstraintGroup.h"

namespace DatabaseTables {
namespace Constraints{
namespace Groups{

ConstraintGroup::ConstraintGroup(){}
ConstraintGroup::~ConstraintGroup(){}

void ConstraintGroup::addConstrint(DatabaseTables::Constraint* constraint)
{
	this->constrints.push_back(constraint);
}

void ConstraintGroup::getTableNames(std::vector<std::string>* tables)
{
	std::vector<IConstraint*>::iterator constraintIt;
	for(constraintIt = this->constrints.begin(); constraintIt != this->constrints.end(); constraintIt++)
		(*constraintIt)->getTableNames(tables);
	
}

}
}
}