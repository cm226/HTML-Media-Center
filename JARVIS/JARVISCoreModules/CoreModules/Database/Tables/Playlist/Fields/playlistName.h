#ifndef _DATABASETABLES_PLAYLIST_FIELDS_PLAYLISTNAME_ 
#define _DATABASETABLES_PLAYLIST_FIELDS_PLAYLISTNAME_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Playlist{ 
namespace Fields{ 
class DLLCORE_API playlistName : public DatabaseTables::DatabaseTableField<std::string>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  playlistName();
  ~playlistName();
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