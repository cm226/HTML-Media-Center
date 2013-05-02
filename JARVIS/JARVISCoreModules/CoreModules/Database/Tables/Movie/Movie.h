#ifndef _DATABASETABLES_MOVIE_MOVIE_ 
#define _DATABASETABLES_MOVIE_MOVIE_
#include "../DatabaseTable.h"
#include <sstream>
#include "../../../exportMacros.h"
#include "Fields/movieID.h"
#include "Fields/movieName.h"
#include "Fields/movieURL.h"
#include "Fields/movieIMDB.h"
#include "Fields/movieGenre.h"
#include "Fields/thumbnailURL.h"
namespace DatabaseTables{ 
namespace Movie{ 
class DLLCORE_API Movie : public DatabaseTables::DatabaseTable{ 
//Member Variables
private:
public:
Fields::movieID* movieID;
Fields::movieName* movieName;
Fields::movieURL* movieURL;
Fields::movieIMDB* movieIMDB;
Fields::movieGenre* movieGenre;
Fields::thumbnailURL* thumbnailURL;
protected:
//Methods
private:
public:
  Movie();
  ~Movie();
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