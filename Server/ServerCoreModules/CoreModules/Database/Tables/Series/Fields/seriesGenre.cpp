#include "seriesGenre.h" 
namespace DatabaseTables{ 
namespace Series{ 
namespace Fields{ 
  seriesGenre::seriesGenre():DatabaseTables::DatabaseTableField<std::string>("Series")
 
 {

}
  seriesGenre::~seriesGenre() 
 {

}
std::string seriesGenre::getName() 
 {
return "Series.seriesGenre";
}
std::string seriesGenre::fieldName() 
 {
return "seriesGenre";
}
std::string seriesGenre::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void seriesGenre::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("seriesGenre");this->setValue(&value);
}
}
}
}
