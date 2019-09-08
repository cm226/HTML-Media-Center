#include "movieName.h" 
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
  movieName::movieName():DatabaseTables::DatabaseTableField<std::string>("Movie")
 
 {

}
  movieName::~movieName() 
 {

}
std::string movieName::getName() 
 {
return "Movie.movieName";
}
std::string movieName::fieldName() 
 {
return "movieName";
}
std::string movieName::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void movieName::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("movieName");this->setValue(&value);
}
}
}
}
