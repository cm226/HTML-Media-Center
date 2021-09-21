#ifndef _DATABASETABLES_SERIES_FIELDS_SERIESGENRE_ 
#define _DATABASETABLES_SERIES_FIELDS_SERIESGENRE_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Series{ 
namespace Fields{ 
class DLLCORE_API seriesGenre : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  seriesGenre();
  ~seriesGenre();
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