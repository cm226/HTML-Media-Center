#ifndef _DATABASETABLES_SERIES_FIELDS_SERIESIMDB_ 
#define _DATABASETABLES_SERIES_FIELDS_SERIESIMDB_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Series{ 
namespace Fields{ 
class DLLCORE_API seriesIMDB : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  seriesIMDB();
  ~seriesIMDB();
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