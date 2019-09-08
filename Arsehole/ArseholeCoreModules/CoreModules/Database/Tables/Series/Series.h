#ifndef _DATABASETABLES_SERIES_SERIES_ 
#define _DATABASETABLES_SERIES_SERIES_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/seriesName.h"
#include "Fields/seriesIMDB.h"
#include "Fields/seriesGenre.h"
namespace DatabaseTables{ 
namespace Series{ 
class DLLCORE_API Series : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::seriesName* seriesName;
Fields::seriesIMDB* seriesIMDB;
Fields::seriesGenre* seriesGenre;
protected:
//Methods
private:
public:
  Series();
  ~Series();
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