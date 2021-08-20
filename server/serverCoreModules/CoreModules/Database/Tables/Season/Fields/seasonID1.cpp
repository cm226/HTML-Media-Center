#include "seasonID.h" 
namespace DatabaseTables{ 
namespace Season{ 
namespace Fields{ 
  seasonID::seasonID():DatabaseTables::DatabaseTableField<int>("Season")
 
 {

}
  seasonID::~seasonID() 
 {

}
std::string seasonID::getName() 
 {
return "Season.seasonID";
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
