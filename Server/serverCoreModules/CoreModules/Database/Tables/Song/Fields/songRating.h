#ifndef _DATABASETABLES_SONG_FIELDS_SONGRATING_ 
#define _DATABASETABLES_SONG_FIELDS_SONGRATING_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
class DLLCORE_API songRating : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  songRating();
  ~songRating();
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