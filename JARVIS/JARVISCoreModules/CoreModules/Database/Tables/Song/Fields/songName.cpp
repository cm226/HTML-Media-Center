#include "songName.h" 
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
  songName::songName():DatabaseTables::DatabaseTableField<std::string>("Song")
 
 {

}
  songName::~songName() 
 {

}
std::string songName::getName() 
 {
return "Song.songName";
}
std::string songName::fieldName() 
 {
return "songName";
}
std::string songName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void songName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("songName");this->setValue(&value);
}
}
}
}
