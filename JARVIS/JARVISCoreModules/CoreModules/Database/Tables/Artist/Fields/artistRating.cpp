#include "artistRating.h" 
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
  artistRating::artistRating():DatabaseTables::DatabaseTableField<int>("Artist")
 
 {

}
  artistRating::~artistRating() 
 {

}
std::string artistRating::getName() 
 {
return "Artist.artistRating";
}
std::string artistRating::fieldName() 
 {
return "artistRating";
}
std::string artistRating::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void artistRating::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("artistRating");this->setValue(&value);
}
}
}
}
