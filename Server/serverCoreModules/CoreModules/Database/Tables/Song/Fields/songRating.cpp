#include "songRating.h" 
namespace DatabaseTables{ 
namespace Song{ 
namespace Fields{ 
  songRating::songRating():DatabaseTables::DatabaseTableField<int>("Song")
 
 {

}
  songRating::~songRating() 
 {

}
std::string songRating::getName() 
 {
return "Song.songRating";
}
std::string songRating::fieldName() 
 {
return "songRating";
}
std::string songRating::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void songRating::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("songRating");this->setValue(&value);
}
}
}
}
