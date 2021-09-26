#ifndef _DATABASETABLES_SEASON_FIELDS_SERIESNAME_ 
#define _DATABASETABLES_SEASON_FIELDS_SERIESNAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Season{ 
namespace Fields{ 
class DLLCORE_API seriesName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  seriesName();
  ~seriesName();
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