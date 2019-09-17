#include "seasonID.h" 
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
  seasonID::seasonID():DatabaseTables::DatabaseTableField<int>("Episode")
 
 {

}
  seasonID::~seasonID() 
 {

}
std::string seasonID::getName() 
 {
return "Episode.seasonID";
}
std::string seasonID::fieldName() 
 {
return "seasonID";
}
std::string seasonID::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void seasonID::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("seasonID");this->setValue(&value);
}
}
}
}
