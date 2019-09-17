#ifndef _DATABASETABLES_PICTURE_PICTURE_ 
#define _DATABASETABLES_PICTURE_PICTURE_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/picName.h"
#include "Fields/picURL.h"
#include "Fields/albumName.h"
namespace DatabaseTables{ 
namespace Picture{ 
class DLLCORE_API Picture : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::picName* picName;
Fields::picURL* picURL;
Fields::albumName* albumName;
protected:
//Methods
private:
public:
  Picture();
  ~Picture();
std::string getUpdateQuery();
std::string getInsertQuery();
void getFields(std::vector<IDatabaseTableField*>* fields);
DatabaseTables::IDatabaseTableField* getPrimaryKey();
std::string tableName();
protected:
}; 
}
}
 #endif