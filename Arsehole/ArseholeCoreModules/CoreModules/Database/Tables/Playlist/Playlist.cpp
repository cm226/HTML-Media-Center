#include "Playlist.h" 
namespace DatabaseTables{ 
namespace Playlist{ 
  Playlist::Playlist():DatabaseTables::DatabaseTable()
 
 {
this->playlistName = new Fields::playlistName(); 
this->playlistPlayCount = new Fields::playlistPlayCount(); 

}
  Playlist::~Playlist() 
 {
delete this->playlistName;
delete this->playlistPlayCount;

}
std::string Playlist::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Playlist SET ";
return update.str();

}
std::string Playlist::getInsertQuery() 
 {
return NULL;
}
void Playlist::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->playlistName); 
fields->push_back(this->playlistPlayCount); 

}
DatabaseTables::IDatabaseTableField* Playlist::getPrimaryKey() 
 {
return this->playlistName;
}
std::string Playlist::tableName() 
 {
return "Playlist";
}
}
}
