#ifndef _DATABASETABLES_EPISODE_FIELDS_FILEPATH_ 
#define _DATABASETABLES_EPISODE_FIELDS_FILEPATH_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
class DLLCORE_API filePath : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  filePath();
  ~filePath();
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