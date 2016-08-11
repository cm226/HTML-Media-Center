#ifndef _DATABASETABLES_ALBUM_ALBUM_ 
#define _DATABASETABLES_ALBUM_ALBUM_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/albumID.h"
#include "Fields/albumName.h"
#include "Fields/artistID.h"
#include "Fields/albumRating.h"
namespace DatabaseTables{ 
namespace Album{ 
class DLLCORE_API Album : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::albumID* albumID;
Fields::albumName* albumName;
Fields::artistID* artistID;
Fields::albumRating* albumRating;
protected:
//Methods
private:
public:
  Album();
  ~Album();
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