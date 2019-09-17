#include "playlistPlayCount.h" 
namespace DatabaseTables{ 
namespace Playlist{ 
namespace Fields{ 
  playlistPlayCount::playlistPlayCount():DatabaseTables::DatabaseTableField<int>("Playlist")
 
 {

}
  playlistPlayCount::~playlistPlayCount() 
 {

}
std::string playlistPlayCount::getName() 
 {
return "Playlist.playlistPlayCount";
}
std::string playlistPlayCount::fieldName() 
 {
return "playlistPlayCount";
}
std::string playlistPlayCount::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void playlistPlayCount::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("playlistPlayCount");this->setValue(&value);
}
}
}
}
