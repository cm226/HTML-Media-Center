#ifndef _DATABASETABLES_SONG_SONG_ 
#define _DATABASETABLES_SONG_SONG_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/songID.h"
#include "Fields/songName.h"
#include "Fields/albumID.h"
#include "Fields/songRating.h"
#include "Fields/playCount.h"
#include "Fields/songURL.h"
namespace DatabaseTables{ 
namespace Song{ 
class DLLCORE_API Song : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::songID* songID;
Fields::songName* songName;
Fields::albumID* albumID;
Fields::songRating* songRating;
Fields::playCount* playCount;
Fields::songURL* songURL;
protected:
//Methods
private:
public:
  Song();
  ~Song();
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