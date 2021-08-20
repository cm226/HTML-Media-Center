#ifndef _DATABASETABLES_ALBUM_FIELDS_ALBUMRATING_ 
#define _DATABASETABLES_ALBUM_FIELDS_ALBUMRATING_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Album{ 
namespace Fields{ 
class DLLCORE_API albumRating : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  albumRating();
  ~albumRating();
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