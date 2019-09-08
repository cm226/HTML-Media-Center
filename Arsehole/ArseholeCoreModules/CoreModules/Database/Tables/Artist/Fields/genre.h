#ifndef _DATABASETABLES_ARTIST_FIELDS_GENRE_ 
#define _DATABASETABLES_ARTIST_FIELDS_GENRE_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
class DLLCORE_API genre : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  genre();
  ~genre();
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