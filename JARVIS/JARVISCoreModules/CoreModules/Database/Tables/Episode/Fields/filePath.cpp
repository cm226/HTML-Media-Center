#include "filePath.h" 
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
  filePath::filePath():DatabaseTables::DatabaseTableField<std::string>("Episode")
 
 {

}
  filePath::~filePath() 
 {

}
std::string filePath::getName() 
 {
return "Episode.filePath";
}
std::string filePath::fieldName() 
 {
return "filePath";
}
std::string filePath::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void filePath::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("filePath");this->setValue(&value);
}
}
}
}
