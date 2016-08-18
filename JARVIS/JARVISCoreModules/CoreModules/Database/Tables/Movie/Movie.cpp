#include "Movie.h" 
namespace DatabaseTables{ 
namespace Movie{ 
  Movie::Movie():DatabaseTables::DatabaseTable()
 
 {
this->movieID = new Fields::movieID(); 
this->movieName = new Fields::movieName(); 
this->movieURL = new Fields::movieURL(); 
this->movieIMDB = new Fields::movieIMDB(); 
this->movieGenre = new Fields::movieGenre(); 
this->thumbnailURL = new Fields::thumbnailURL(); 

}
  Movie::~Movie() 
 {
delete this->movieID;
delete this->movieName;
delete this->movieURL;
delete this->movieIMDB;
delete this->movieGenre;
delete this->thumbnailURL;

}
std::string Movie::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Movie SET ";
return update.str();

}
std::string Movie::getInsertQuery() 
 {
return NULL;
}
void Movie::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->movieID); 
fields->push_back(this->movieName); 
fields->push_back(this->movieURL); 
fields->push_back(this->movieIMDB); 
fields->push_back(this->movieGenre); 
fields->push_back(this->thumbnailURL); 

}
DatabaseTables::IDatabaseTableField* Movie::getPrimaryKey() 
 {
return this->movieID;
}
std::string Movie::tableName() 
 {
return "Movie";
}
}
}
