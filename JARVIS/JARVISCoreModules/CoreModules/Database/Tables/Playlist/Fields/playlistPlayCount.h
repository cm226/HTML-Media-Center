#ifndef _DATABASETABLES_PLAYLIST_FIELDS_PLAYLISTPLAYCOUNT_ 
#define _DATABASETABLES_PLAYLIST_FIELDS_PLAYLISTPLAYCOUNT_
#include <sstream>
#include "../../DatabaseTableField.h"
#include "../../../../exportMacros.h"
namespace DatabaseTables{ 
namespace Playlist{ 
namespace Fields{ 
class DLLCORE_API playlistPlayCount : public DatabaseTables::DatabaseTableField<int>{ 
//Member Variables
private:
public:
protected:
//Methods
private:
public:
  playlistPlayCount();
  ~playlistPlayCount();
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