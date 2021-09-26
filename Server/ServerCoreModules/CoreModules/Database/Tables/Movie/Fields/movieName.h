#ifndef _DATABASETABLES_MOVIE_FIELDS_MOVIENAME_ 
#define _DATABASETABLES_MOVIE_FIELDS_MOVIENAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
class DLLCORE_API movieName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  movieName();
  ~movieName();
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