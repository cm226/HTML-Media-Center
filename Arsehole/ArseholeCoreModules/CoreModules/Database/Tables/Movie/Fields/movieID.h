#ifndef _DATABASETABLES_MOVIE_FIELDS_MOVIEID_ 
#define _DATABASETABLES_MOVIE_FIELDS_MOVIEID_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
class DLLCORE_API movieID : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  movieID();
  ~movieID();
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