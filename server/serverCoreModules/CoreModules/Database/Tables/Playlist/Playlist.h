#ifndef _DATABASETABLES_PLAYLIST_PLAYLIST_ 
#define _DATABASETABLES_PLAYLIST_PLAYLIST_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/playlistName.h"
#include "Fields/playlistPlayCount.h"
namespace DatabaseTables{ 
namespace Playlist{ 
class DLLCORE_API Playlist : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::playlistName* playlistName;
Fields::playlistPlayCount* playlistPlayCount;
protected:
//Methods
private:
public:
  Playlist();
  ~Playlist();
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