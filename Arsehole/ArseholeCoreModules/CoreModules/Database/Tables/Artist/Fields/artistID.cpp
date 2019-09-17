#include "artistID.h" 
namespace DatabaseTables{ 
namespace Artist{ 
namespace Fields{ 
  artistID::artistID():DatabaseTables::DatabaseTableField<int>("Artist")
 
 {

}
  artistID::~artistID() 
 {

}
std::string artistID::getName() 
 {
return "Artist.artistID";
}
std::string artistID::fieldName() 
 {
return "artistID";
}
std::string artistID::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void artistID::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("artistID");this->setValue(&value);
}
}
}
}
