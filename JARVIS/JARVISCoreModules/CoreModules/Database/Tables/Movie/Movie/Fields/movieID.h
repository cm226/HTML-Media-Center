#ifndef _MOVIEID_H
#define _MOVIEID_H

#include "../../../DatabaseTableField.h"
#include "../../../../../exportMacros.h"

namespace DatabaseTables
{

class DLLCORE_API movieID : public DatabaseTableField<int>
{
public:
	movieID(void);
	~movieID(void);

	std::string getName();

	void takeValue(ResultWrapper* resRwapper);
	std::string fieldName();

	std::string getStrValue();
};

}

#endif

