#include "playCount.h" 
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
  playCount::playCount():DatabaseTables::DatabaseTableField<int>("Song")
 
 {

}
  playCount::~playCount() 
 {

}
std::string playCount::getName() 
 {
return "Song.playCount";
}
std::string playCount::fieldName() 
 {
return "playCount";
}
std::string playCount::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void playCount::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("playCount");this->setValue(&value);
}
}
}
}
