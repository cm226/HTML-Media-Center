#ifndef _MOVIEURL_H
#define _MOVIEURL_H
#include "../../../DatabaseTableField.h"
#include "../../../../../exportMacros.h"

namespace DatabaseTables
{

class DLLCORE_API movieURL : public DatabaseTableField<std::string>
{
public:
	movieURL(void);
	~movieURL(void);

	std::string getName();
	void takeValue(ResultWrapper* resRwapper);
	std::string fieldName();

	std::string getStrValue();
};
}

#endif

