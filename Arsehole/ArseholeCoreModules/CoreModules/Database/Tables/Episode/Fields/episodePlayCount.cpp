#include "episodePlayCount.h" 
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
  episodePlayCount::episodePlayCount():DatabaseTables::DatabaseTableField<int>("Episode")
 
 {

}
  episodePlayCount::~episodePlayCount() 
 {

}
std::string episodePlayCount::getName() 
 {
return "Episode.episodePlayCount";
}
std::string episodePlayCount::fieldName() 
 {
return "episodePlayCount";
}
std::string episodePlayCount::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void episodePlayCount::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("episodePlayCount");this->setValue(&value);
}
}
}
}
