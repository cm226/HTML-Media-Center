#ifndef _ORCONSTRINTGROUP_
#define _ORCONSTRINTGROUP_

#include "ConstraintGroup.h"

namespace DatabaseTables {
namespace Constraints
{
	namespace Groups
	{


	class OrConstraintGroup : public ConstraintGroup
	{
	public:
		OrConstraintGroup();
		~OrConstraintGroup();

		std::string OrConstraintGroup::getQuerystring();

	};
}
}}

#endif