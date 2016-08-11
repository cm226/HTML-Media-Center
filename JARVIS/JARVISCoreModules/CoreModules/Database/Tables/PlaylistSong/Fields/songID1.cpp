#include "songID.h" 
namespace DatabaseTables{ 
namespace PlaylistSong{ 
namespace Fields{ 
  songID::songID():DatabaseTables::DatabaseTableField<std::string>("PlaylistSong")
 
 {

}
  songID::~songID() 
 {

}
std::string songID::getName() 
 {
return "PlaylistSong.songID";
}
std::string songID::fieldName() 
 {
return "songID";
}
std::string songID::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void songID::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("songID");this->setValue(&value);
}
}
}
}
