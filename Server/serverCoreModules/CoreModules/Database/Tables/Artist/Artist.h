#ifndef _DATABASETABLES_ARTIST_ARTIST_ 
#define _DATABASETABLES_ARTIST_ARTIST_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/artistID.h"
#include "Fields/artistName.h"
#include "Fields/artistRating.h"
#include "Fields/genre.h"
namespace DatabaseTables{ 
namespace Artist{ 
class DLLCORE_API Artist : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::artistID* artistID;
Fields::artistName* artistName;
Fields::artistRating* artistRating;
Fields::genre* genre;
protected:
//Methods
private:
public:
  Artist();
  ~Artist();
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