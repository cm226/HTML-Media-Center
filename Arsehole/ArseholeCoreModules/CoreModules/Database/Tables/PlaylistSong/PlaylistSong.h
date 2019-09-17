#ifndef _DATABASETABLES_PLAYLISTSONG_PLAYLISTSONG_ 
#define _DATABASETABLES_PLAYLISTSONG_PLAYLISTSONG_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/playlistSongID.h"
#include "Fields/playlistName.h"
#include "Fields/songID.h"
namespace DatabaseTables{ 
namespace PlaylistSong{ 
class DLLCORE_API PlaylistSong : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::playlistSongID* playlistSongID;
Fields::playlistName* playlistName;
Fields::songID* songID;
protected:
//Methods
private:
public:
  PlaylistSong();
  ~PlaylistSong();
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