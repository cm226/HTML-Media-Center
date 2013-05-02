#include "albumName.h" 
namespace DatabaseTables{ 
namespace Album{ 
namespace Fields{ 
  albumName::albumName():DatabaseTables::DatabaseTableField<std::string>("Album")
 
 {

}
  albumName::~albumName() 
 {

}
std::string albumName::getName() 
 {
return "Album.albumName";
}
std::string albumName::fieldName() 
 {
return "albumName";
}
std::string albumName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void albumName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("albumName");this->setValue(&value);
}
}
}
}
