#include "albumRating.h" 
namespace DatabaseTables{ 
namespace Album{ 
namespace Fields{ 
  albumRating::albumRating():DatabaseTables::DatabaseTableField<int>("Album")
 
 {

}
  albumRating::~albumRating() 
 {

}
std::string albumRating::getName() 
 {
return "Album.albumRating";
}
std::string albumRating::fieldName() 
 {
return "albumRating";
}
std::string albumRating::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void albumRating::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("albumRating");this->setValue(&value);
}
}
}
}
