#ifndef _MOVIEIMDB_H
#define _MOVIEIMDB_H

#include "../../../DatabaseTableField.h"
#include "../../../../../exportMacros.h"

namespace DatabaseTables
{

class DLLCORE_API movieIMDB : public DatabaseTableField<std::string>
{
public:
	movieIMDB(void);
	~movieIMDB(void);

	std::string getName();
	void takeValue(ResultWrapper* resRwapper);
	std::string fieldName();

	std::string getStrValue();
};
}

#endif

