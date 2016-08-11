#include "seriesNumber.h" 
namespace DatabaseTables{ 
namespace Season{ 
namespace Fields{ 
  seriesNumber::seriesNumber():DatabaseTables::DatabaseTableField<int>("Season")
 
 {

}
  seriesNumber::~seriesNumber() 
 {

}
std::string seriesNumber::getName() 
 {
return "Season.seriesNumber";
}
std::string seriesNumber::fieldName() 
 {
return "seriesNumber";
}
std::string seriesNumber::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void seriesNumber::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("seriesNumber");this->setValue(&value);
}
}
}
}
