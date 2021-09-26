#include "playlistSongID.h" 
namespace DatabaseTables{ 
namespace PlaylistSong{ 
namespace Fields{ 
  playlistSongID::playlistSongID():DatabaseTables::DatabaseTableField<int>("PlaylistSong")
 
 {

}
  playlistSongID::~playlistSongID() 
 {

}
std::string playlistSongID::getName() 
 {
return "PlaylistSong.playlistSongID";
}
std::string playlistSongID::fieldName() 
 {
return "playlistSongID";
}
std::string playlistSongID::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void playlistSongID::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("playlistSongID");this->setValue(&value);
}
}
}
}
