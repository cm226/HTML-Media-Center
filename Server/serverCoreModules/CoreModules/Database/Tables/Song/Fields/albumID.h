#ifndef _DATABASETABLES_SONG_FIELDS_ALBUMID_ 
#define _DATABASETABLES_SONG_FIELDS_ALBUMID_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
class DLLCORE_API albumID : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  albumID();
  ~albumID();
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