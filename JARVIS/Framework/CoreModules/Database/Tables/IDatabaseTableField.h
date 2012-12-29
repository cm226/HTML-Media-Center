#ifndef _IDATABASETABLEFIELD
#define _IDATABASETABLEFIELD

#include <string>
#include "../ResultWrapper.h"

namespace DatabaseTables {
class IDatabaseFieldType
{
};

template <class T>
class CDatabaseFieldType : public IDatabaseFieldType
{
    T type;
};


class IDatabaseTableField
{
protected:
	   virtual std::string fieldName() = 0;

public:
   virtual ~IDatabaseTableField();

   virtual void takeValue(ResultWrapper* resRwapper) = 0;
   virtual std::string getName() = 0;
   virtual std::string ownerName() = 0;
};


}

#endif
