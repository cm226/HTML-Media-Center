#ifndef _DATABASETABLES_SONG_FIELDS_SONGNAME_ 
#define _DATABASETABLES_SONG_FIELDS_SONGNAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
class DLLCORE_API songName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  songName();
  ~songName();
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