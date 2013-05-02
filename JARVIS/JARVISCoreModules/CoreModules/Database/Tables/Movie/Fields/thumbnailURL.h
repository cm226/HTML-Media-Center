#ifndef _DATABASETABLES_MOVIE_FIELDS_THUMBNAILURL_ 
#define _DATABASETABLES_MOVIE_FIELDS_THUMBNAILURL_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
class DLLCORE_API thumbnailURL : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  thumbnailURL();
  ~thumbnailURL();
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