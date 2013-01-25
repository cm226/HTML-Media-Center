#ifndef _MOVIEGENRA_H
#define _MOVIEGENRA_H

#include <string>
#include "../../../DatabaseTableField.h"
#include "../../../../../exportMacros.h"

namespace DatabaseTables
{

class DLLCORE_API movieGenra : public DatabaseTableField<std::string>
{
public:
	movieGenra(void);
	~movieGenra(void);


	std::string getName();

	void takeValue(ResultWrapper* resRwapper);
	std::string fieldName();

	std::string getStrValue();
};

}
#endif

