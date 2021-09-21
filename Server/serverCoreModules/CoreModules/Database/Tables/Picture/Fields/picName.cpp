#include "picName.h" 
namespace DatabaseTables{ 
namespace Picture{ 
namespace Fields{ 
  picName::picName():DatabaseTables::DatabaseTableField<std::string>("Picture")
 
 {

}
  picName::~picName() 
 {

}
std::string picName::getName() 
 {
return "Picture.picName";
}
std::string picName::fieldName() 
 {
return "picName";
}
std::string picName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void picName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("picName");this->setValue(&value);
}
}
}
}
