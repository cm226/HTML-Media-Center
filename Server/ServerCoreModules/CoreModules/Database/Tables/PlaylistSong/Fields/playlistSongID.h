#ifndef _DATABASETABLES_PLAYLISTSONG_FIELDS_PLAYLISTSONGID_ 
#define _DATABASETABLES_PLAYLISTSONG_FIELDS_PLAYLISTSONGID_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace PlaylistSong{ 
namespace Fields{ 
class DLLCORE_API playlistSongID : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  playlistSongID();
  ~playlistSongID();
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