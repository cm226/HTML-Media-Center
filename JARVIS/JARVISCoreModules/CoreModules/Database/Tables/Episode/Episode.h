#ifndef _DATABASETABLES_EPISODE_EPISODE_ 
#define _DATABASETABLES_EPISODE_EPISODE_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/episodeID.h"
#include "Fields/episodeNumber.h"
#include "Fields/episodeName.h"
#include "Fields/episodePlayCount.h"
#include "Fields/seasonID.h"
#include "Fields/filePath.h"
namespace DatabaseTables{ 
namespace Episode{ 
class DLLCORE_API Episode : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::episodeID* episodeID;
Fields::episodeNumber* episodeNumber;
Fields::episodeName* episodeName;
Fields::episodePlayCount* episodePlayCount;
Fields::seasonID* seasonID;
Fields::filePath* filePath;
protected:
//Methods
private:
public:
  Episode();
  ~Episode();
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