#include "albumID.h" 
namespace DatabaseTables{ 
namespace Album{ 
namespace Fields{ 
  albumID::albumID():DatabaseTables::DatabaseTableField<int>("Album")
 
 {

}
  albumID::~albumID() 
 {

}
std::string albumID::getName() 
 {
return "Album.albumID";
}
std::string albumID::fieldName() 
 {
return "albumID";
}
std::string albumID::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void albumID::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("albumID");this->setValue(&value);
}
}
}
}
