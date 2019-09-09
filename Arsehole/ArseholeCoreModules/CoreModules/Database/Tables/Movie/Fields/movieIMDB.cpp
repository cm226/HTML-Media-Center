#include "movieIMDB.h" 
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
  movieIMDB::movieIMDB():DatabaseTables::DatabaseTableField<std::string>("Movie")
 
 {

}
  movieIMDB::~movieIMDB() 
 {

}
std::string movieIMDB::getName() 
 {
return "Movie.movieIMDB";
}
std::string movieIMDB::fieldName() 
 {
return "movieIMDB";
}
std::string movieIMDB::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void movieIMDB::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("movieIMDB");this->setValue(&value);
}
}
}
}
