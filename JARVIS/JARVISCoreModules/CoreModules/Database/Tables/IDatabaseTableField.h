#ifndef _IDATABASETABLEFIELD
#define _IDATABASETABLEFIELD

#include <string>
#include "../ResultWrapper.h"
#include "../../exportMacros.h"

namespace DatabaseTables {
class DLLCORE_API IDatabaseFieldType
{
};

template <class T>
class DLLCORE_API CDatabaseFieldType : public IDatabaseFieldType
{
    T type;
};


class DLLCORE_API IDatabaseTableField
{
  

public:
   virtual ~IDatabaseTableField();

   virtual void takeValue(ResultWrapper* resRwapper) = 0;
   virtual std::string getName() = 0;
   virtual std::string ownerName() = 0;
   virtual std::string fieldName() = 0;

   virtual std::string getStrValue() = 0;
};


}

#endif
