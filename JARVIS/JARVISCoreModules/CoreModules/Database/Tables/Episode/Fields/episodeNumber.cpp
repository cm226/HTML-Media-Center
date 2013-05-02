#include "episodeNumber.h" 
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
  episodeNumber::episodeNumber():DatabaseTables::DatabaseTableField<int>("Episode")
 
 {

}
  episodeNumber::~episodeNumber() 
 {

}
std::string episodeNumber::getName() 
 {
return "Episode.episodeNumber";
}
std::string episodeNumber::fieldName() 
 {
return "episodeNumber";
}
std::string episodeNumber::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void episodeNumber::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("episodeNumber");this->setValue(&value);
}
}
}
}
