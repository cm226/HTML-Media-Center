#include "songID.h" 
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
  songID::songID():DatabaseTables::DatabaseTableField<int>("Song")
 
 {

}
  songID::~songID() 
 {

}
std::string songID::getName() 
 {
return "Song.songID";
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
int value = resRwapper->getInt("songID");this->setValue(&value);
}
}
}
}
