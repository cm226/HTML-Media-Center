#include "artistName.h" 
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
  artistName::artistName():DatabaseTables::DatabaseTableField<std::string>("Artist")
 
 {

}
  artistName::~artistName() 
 {

}
std::string artistName::getName() 
 {
return "Artist.artistName";
}
std::string artistName::fieldName() 
 {
return "artistName";
}
std::string artistName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void artistName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("artistName");this->setValue(&value);
}
}
}
}
