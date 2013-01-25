#ifndef MOVIELENGTH_
#define MOVIELENGTH_

#include "../../../DatabaseTableField.h"
#include "../../../../../exportMacros.h"

namespace DatabaseTables
{

class DLLCORE_API movieLength : public DatabaseTableField<std::string>
{
public:
	movieLength(void);
	~movieLength(void);

	std::string getName();
	void takeValue(ResultWrapper* resRwapper);
	std::string fieldName();
	std::string getStrValue();
};
}

#endif
