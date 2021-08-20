#ifndef _DATABASETABLES_ARTIST_FIELDS_ARTISTNAME_ 
#define _DATABASETABLES_ARTIST_FIELDS_ARTISTNAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
class DLLCORE_API artistName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  artistName();
  ~artistName();
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