#include "genre.h" 
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
  genre::genre():DatabaseTables::DatabaseTableField<std::string>("Artist")
 
 {

}
  genre::~genre() 
 {

}
std::string genre::getName() 
 {
return "Artist.genre";
}
std::string genre::fieldName() 
 {
return "genre";
}
std::string genre::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void genre::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("genre");this->setValue(&value);
}
}
}
}
