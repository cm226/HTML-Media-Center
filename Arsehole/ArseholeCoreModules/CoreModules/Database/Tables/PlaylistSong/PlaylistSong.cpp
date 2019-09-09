#include "PlaylistSong.h" 
namespace DatabaseTables{ 
namespace PlaylistSong{ 
  PlaylistSong::PlaylistSong():DatabaseTables::DatabaseTable()
 
 {
this->playlistSongID = new Fields::playlistSongID(); 
this->playlistName = new Fields::playlistName(); 
this->songID = new Fields::songID(); 

}
  PlaylistSong::~PlaylistSong() 
 {
delete this->playlistSongID;
delete this->playlistName;
delete this->songID;

}
std::string PlaylistSong::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE PlaylistSong SET ";
return update.str();

}
std::string PlaylistSong::getInsertQuery() 
 {
return NULL;
}
void PlaylistSong::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->playlistSongID); 
fields->push_back(this->playlistName); 
fields->push_back(this->songID); 

}
DatabaseTables::IDatabaseTableField* PlaylistSong::getPrimaryKey() 
 {
return this->playlistSongID;
}
std::string PlaylistSong::tableName() 
 {
return "PlaylistSong";
}
}
}
