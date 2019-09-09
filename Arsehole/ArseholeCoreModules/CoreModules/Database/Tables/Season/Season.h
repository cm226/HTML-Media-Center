#ifndef _DATABASETABLES_SEASON_SEASON_ 
#define _DATABASETABLES_SEASON_SEASON_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/seasonID.h"
#include "Fields/seriesName.h"
#include "Fields/seriesNumber.h"
namespace DatabaseTables{ 
namespace Season{ 
class DLLCORE_API Season : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::seasonID* seasonID;
Fields::seriesName* seriesName;
Fields::seriesNumber* seriesNumber;
protected:
//Methods
private:
public:
  Season();
  ~Season();
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