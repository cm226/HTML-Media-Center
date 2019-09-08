#include "seriesName.h" 
namespace DatabaseTables{ 
namespace Series{ 
namespace Fields{ 
  seriesName::seriesName():DatabaseTables::DatabaseTableField<std::string>("Series")
 
 {

}
  seriesName::~seriesName() 
 {

}
std::string seriesName::getName() 
 {
return "Series.seriesName";
}
std::string seriesName::fieldName() 
 {
return "seriesName";
}
std::string seriesName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void seriesName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("seriesName");this->setValue(&value);
}
}
}
}
