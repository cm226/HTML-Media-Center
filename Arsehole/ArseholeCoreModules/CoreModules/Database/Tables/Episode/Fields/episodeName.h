#ifndef _DATABASETABLES_EPISODE_FIELDS_EPISODENAME_ 
#define _DATABASETABLES_EPISODE_FIELDS_EPISODENAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
class DLLCORE_API episodeName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  episodeName();
  ~episodeName();
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