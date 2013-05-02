#ifndef _DATABASETABLES_SONG_FIELDS_PLAYCOUNT_ 
#define _DATABASETABLES_SONG_FIELDS_PLAYCOUNT_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
class DLLCORE_API playCount : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  playCount();
  ~playCount();
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