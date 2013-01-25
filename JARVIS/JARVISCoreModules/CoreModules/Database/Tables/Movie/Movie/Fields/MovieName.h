#ifndef _MOVIENAME_H
#define _MOVIENAME_H


#include <string>
#include "../../../DatabaseTableField.h"
#include "../../../../../exportMacros.h"

namespace DatabaseTables
{

class DLLCORE_API MovieName : public DatabaseTableField<std::string>
{
public:
	MovieName(void);
	~MovieName(void);

		std::string getName();
	void takeValue(ResultWrapper* resRwapper);
	std::string fieldName();

	std::string getStrValue();
};

}
#endif
