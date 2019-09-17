#ifndef _DATABASETABLES_PICTURE_FIELDS_PICURL_ 
#define _DATABASETABLES_PICTURE_FIELDS_PICURL_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Picture{ 
namespace Fields{ 
class DLLCORE_API picURL : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  picURL();
  ~picURL();
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