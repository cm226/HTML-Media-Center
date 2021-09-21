#include "episodeID.h" 
namespace DatabaseTables{ 
namespace Episode{ 
namespace Fields{ 
  episodeID::episodeID():DatabaseTables::DatabaseTableField<int>("Episode")
 
 {

}
  episodeID::~episodeID() 
 {

}
std::string episodeID::getName() 
 {
return "Episode.episodeID";
}
std::string episodeID::fieldName() 
 {
return "episodeID";
}
std::string episodeID::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void episodeID::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("episodeID");this->setValue(&value);
}
}
}
}
