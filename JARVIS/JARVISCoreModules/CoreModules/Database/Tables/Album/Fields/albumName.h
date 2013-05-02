#ifndef _DATABASETABLES_ALBUM_FIELDS_ALBUMNAME_ 
#define _DATABASETABLES_ALBUM_FIELDS_ALBUMNAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Album{ 
namespace Fields{ 
class DLLCORE_API albumName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  albumName();
  ~albumName();
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