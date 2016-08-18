#include "playlistName.h" 
namespace DatabaseTables{ 
namespace Playlist{ 
namespace Fields{ 
  playlistName::playlistName():DatabaseTables::DatabaseTableField<std::string>("Playlist")
 
 {

}
  playlistName::~playlistName() 
 {

}
std::string playlistName::getName() 
 {
return "Playlist.playlistName";
}
std::string playlistName::fieldName() 
 {
return "playlistName";
}
std::string playlistName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void playlistName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("playlistName");this->setValue(&value);
}
}
}
}
