#ifndef _DATABASETABLES_SONG_FIELDS_SONGID_ 
#define _DATABASETABLES_SONG_FIELDS_SONGID_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
class DLLCORE_API songID : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  songID();
  ~songID();
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