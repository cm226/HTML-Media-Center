#include "Album.h" 
namespace DatabaseTables{ 
namespace Album{ 
  Album::Album():DatabaseTables::DatabaseTable()
 
 {
this->albumID = new Fields::albumID(); 
this->albumName = new Fields::albumName(); 
this->artistID = new Fields::artistID(); 
this->albumRating = new Fields::albumRating(); 

}
  Album::~Album() 
 {
delete this->albumID;
delete this->albumName;
delete this->artistID;
delete this->albumRating;

}
std::string Album::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Album SET ";
return update.str();

}
std::string Album::getInsertQuery() 
 {
return NULL;
}
void Album::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->albumID); 
fields->push_back(this->albumName); 
fields->push_back(this->artistID); 
fields->push_back(this->albumRating); 

}
DatabaseTables::IDatabaseTableField* Album::getPrimaryKey() 
 {
return this->albumID;
}
std::string Album::tableName() 
 {
return "Album";
}
}
}
