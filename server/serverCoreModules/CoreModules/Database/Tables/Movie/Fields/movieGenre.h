#ifndef _DATABASETABLES_MOVIE_FIELDS_MOVIEGENRE_ 
#define _DATABASETABLES_MOVIE_FIELDS_MOVIEGENRE_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
class DLLCORE_API movieGenre : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  movieGenre();
  ~movieGenre();
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