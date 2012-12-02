#ifndef _IDATABASETABLEFIELD
#define _IDATABASETABLEFIELD

#include <string>
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
public:
   virtual ~IDatabaseTableField();
   virtual void setValue(IDatabaseFieldType* newValue) = 0;
   virtual std::string getName() = 0;
};


}

#endif
