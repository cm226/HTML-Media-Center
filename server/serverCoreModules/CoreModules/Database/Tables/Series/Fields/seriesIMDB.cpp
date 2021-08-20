#include "seriesIMDB.h" 
namespace DatabaseTables{ 
namespace Series{ 
namespace Fields{ 
  seriesIMDB::seriesIMDB():DatabaseTables::DatabaseTableField<int>("Series")
 
 {

}
  seriesIMDB::~seriesIMDB() 
 {

}
std::string seriesIMDB::getName() 
 {
return "Series.seriesIMDB";
}
std::string seriesIMDB::fieldName() 
 {
return "seriesIMDB";
}
std::string seriesIMDB::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void seriesIMDB::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("seriesIMDB");this->setValue(&value);
}
}
}
}
