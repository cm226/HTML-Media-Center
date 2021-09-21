#include "episodeName.h" 
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
  episodeName::episodeName():DatabaseTables::DatabaseTableField<std::string>("Episode")
 
 {

}
  episodeName::~episodeName() 
 {

}
std::string episodeName::getName() 
 {
return "Episode.episodeName";
}
std::string episodeName::fieldName() 
 {
return "episodeName";
}
std::string episodeName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void episodeName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("episodeName");this->setValue(&value);
}
}
}
}
