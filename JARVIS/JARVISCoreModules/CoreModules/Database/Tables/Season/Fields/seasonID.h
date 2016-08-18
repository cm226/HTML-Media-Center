#ifndef _DATABASETABLES_SEASON_FIELDS_SEASONID_ 
#define _DATABASETABLES_SEASON_FIELDS_SEASONID_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Season{ 
namespace Fields{ 
class DLLCORE_API seasonID : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  seasonID();
  ~seasonID();
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