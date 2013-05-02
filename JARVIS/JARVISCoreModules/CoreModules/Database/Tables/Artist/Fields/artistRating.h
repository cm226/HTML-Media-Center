#ifndef _DATABASETABLES_ARTIST_FIELDS_ARTISTRATING_ 
#define _DATABASETABLES_ARTIST_FIELDS_ARTISTRATING_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
class DLLCORE_API artistRating : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  artistRating();
  ~artistRating();
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