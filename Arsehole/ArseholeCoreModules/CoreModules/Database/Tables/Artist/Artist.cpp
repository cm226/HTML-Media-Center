#include "Artist.h" 
namespace DatabaseTables{ 
namespace Artist{ 
  Artist::Artist():DatabaseTables::DatabaseTable()
 
 {
this->artistID = new Fields::artistID(); 
this->artistName = new Fields::artistName(); 
this->artistRating = new Fields::artistRating(); 
this->genre = new Fields::genre(); 

}
  Artist::~Artist() 
 {
delete this->artistID;
delete this->artistName;
delete this->artistRating;
delete this->genre;

}
std::string Artist::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Artist SET ";
return update.str();

}
std::string Artist::getInsertQuery() 
 {
return NULL;
}
void Artist::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->artistID); 
fields->push_back(this->artistName); 
fields->push_back(this->artistRating); 
fields->push_back(this->genre); 

}
DatabaseTables::IDatabaseTableField* Artist::getPrimaryKey() 
 {
return this->artistID;
}
std::string Artist::tableName() 
 {
return "Artist";
}
}
}
