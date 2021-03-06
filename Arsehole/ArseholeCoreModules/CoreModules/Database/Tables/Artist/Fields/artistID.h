#ifndef _DATABASETABLES_ARTIST_FIELDS_ARTISTID_ 
#define _DATABASETABLES_ARTIST_FIELDS_ARTISTID_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
class DLLCORE_API artistID : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  artistID();
  ~artistID();
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