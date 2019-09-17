#include "movieID.h" 
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
  movieID::movieID():DatabaseTables::DatabaseTableField<int>("Movie")
 
 {

}
  movieID::~movieID() 
 {

}
std::string movieID::getName() 
 {
return "Movie.movieID";
}
std::string movieID::fieldName() 
 {
return "movieID";
}
std::string movieID::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void movieID::takeValue(ResultWrapper* resRwapper) 
 {
int value = resRwapper->getInt("movieID");this->setValue(&value);
}
}
}
}
