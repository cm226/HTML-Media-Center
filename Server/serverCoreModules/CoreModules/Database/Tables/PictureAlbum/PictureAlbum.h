#ifndef _DATABASETABLES_PICTUREALBUM_PICTUREALBUM_ 
#define _DATABASETABLES_PICTUREALBUM_PICTUREALBUM_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/albumName.h"
namespace DatabaseTables{ 
namespace PictureAlbum{ 
class DLLCORE_API PictureAlbum : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::albumName* albumName;
protected:
//Methods
private:
public:
  PictureAlbum();
  ~PictureAlbum();
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