#ifndef _DATABASETABLES_PICTURE_FIELDS_PICNAME_ 
#define _DATABASETABLES_PICTURE_FIELDS_PICNAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Picture{ 
namespace Fields{ 
class DLLCORE_API picName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  picName();
  ~picName();
std::string getName();
std::string fieldName();
std::string getStrValue();
void takeValue(ResultWrapper* resRwapper);
protected:
}; 
}
}
}
 #endif