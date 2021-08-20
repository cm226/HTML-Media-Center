#include "Song.h" 
namespace DatabaseTables{ 
namespace Song{ 
  Song::Song():DatabaseTables::DatabaseTable()
 
 {
this->songID = new Fields::songID(); 
this->songName = new Fields::songName(); 
this->albumID = new Fields::albumID(); 
this->songRating = new Fields::songRating(); 
this->playCount = new Fields::playCount(); 
this->songURL = new Fields::songURL(); 

}
  Song::~Song() 
 {
delete this->songID;
delete this->songName;
delete this->albumID;
delete this->songRating;
delete this->playCount;
delete this->songURL;

}
std::string Song::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Song SET ";
return update.str();

}
std::string Song::getInsertQuery() 
 {
return NULL;
}
void Song::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->songID); 
fields->push_back(this->songName); 
fields->push_back(this->albumID); 
fields->push_back(this->songRating); 
fields->push_back(this->playCount); 
fields->push_back(this->songURL); 

}
DatabaseTables::IDatabaseTableField* Song::getPrimaryKey() 
 {
return this->songID;
}
std::string Song::tableName() 
 {
return "Song";
}
}
}
