#include "movieURL.h" 
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
  movieURL::movieURL():DatabaseTables::DatabaseTableField<std::string>("Movie")
 
 {

}
  movieURL::~movieURL() 
 {

}
std::string movieURL::getName() 
 {
return "Movie.movieURL";
}
std::string movieURL::fieldName() 
 {
return "movieURL";
}
std::string movieURL::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void movieURL::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("movieURL");this->setValue(&value);
}
}
}
}
