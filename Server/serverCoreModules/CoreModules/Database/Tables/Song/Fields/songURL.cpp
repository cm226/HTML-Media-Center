#include "songURL.h" 
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
  songURL::songURL():DatabaseTables::DatabaseTableField<std::string>("Song")
 
 {

}
  songURL::~songURL() 
 {

}
std::string songURL::getName() 
 {
return "Song.songURL";
}
std::string songURL::fieldName() 
 {
return "songURL";
}
std::string songURL::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void songURL::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("songURL");this->setValue(&value);
}
}
}
}
