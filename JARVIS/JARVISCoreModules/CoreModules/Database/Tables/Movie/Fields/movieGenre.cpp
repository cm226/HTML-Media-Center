#include "movieGenre.h" 
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
  movieGenre::movieGenre():DatabaseTables::DatabaseTableField<std::string>("Movie")
 
 {

}
  movieGenre::~movieGenre() 
 {

}
std::string movieGenre::getName() 
 {
return "Movie.movieGenre";
}
std::string movieGenre::fieldName() 
 {
return "movieGenre";
}
std::string movieGenre::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void movieGenre::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("movieGenre");this->setValue(&value);
}
}
}
}
