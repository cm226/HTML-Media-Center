#ifndef _MOVIETHUMBNAIL_H
#define _MOVIETHUMBNAIL_H

#include "../../../DatabaseTableField.h"
#include "../../../../../exportMacros.h"
#include <string>

namespace DatabaseTables
{

class DLLCORE_API thumbnailURL : public DatabaseTableField<std::string>
{
public:
	thumbnailURL(void);
	~thumbnailURL(void);

	std::string getName();
	void takeValue(ResultWrapper* resRwapper);
	std::string fieldName();

	std::string getStrValue();

};
}

#endif
