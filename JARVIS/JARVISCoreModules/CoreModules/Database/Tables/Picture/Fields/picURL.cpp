#include "picURL.h" 
namespace DatabaseTables{ 
namespace Picture{ 
namespace Fields{ 
  picURL::picURL():DatabaseTables::DatabaseTableField<std::string>("Picture")
 
 {

}
  picURL::~picURL() 
 {

}
std::string picURL::getName() 
 {
return "Picture.picURL";
}
std::string picURL::fieldName() 
 {
return "picURL";
}
std::string picURL::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void picURL::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("picURL");this->setValue(&value);
}
}
}
}
