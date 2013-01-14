#include "ORConstraintGroup.h"

namespace DatabaseTables {
namespace Constraints
{
	namespace Groups
	{

OrConstraintGroup::OrConstraintGroup(){}
OrConstraintGroup::~OrConstraintGroup(){}

std::string OrConstraintGroup::getQuerystring()
{
	std::string qstr = " (";
	std::vector<IConstraint*>::iterator constraintIt;
	for(constraintIt = this->constrints.begin(); constraintIt != this->constrints.end(); constraintIt++)
	{
		if(constraintIt != this->constrints.begin())
			qstr+= "OR ";

		qstr += (*constraintIt)->getQuerystring()+" ";
	}

	qstr+= ") ";
	return qstr;
}

	}}}