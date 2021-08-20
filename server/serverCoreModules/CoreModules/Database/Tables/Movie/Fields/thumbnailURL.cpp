#include "thumbnailURL.h" 
namespace DatabaseTables{ 
namespace Movie{ 
namespace Fields{ 
  thumbnailURL::thumbnailURL():DatabaseTables::DatabaseTableField<std::string>("Movie")
 
 {

}
  thumbnailURL::~thumbnailURL() 
 {

}
std::string thumbnailURL::getName() 
 {
return "Movie.thumbnailURL";
}
std::string thumbnailURL::fieldName() 
 {
return "thumbnailURL";
}
std::string thumbnailURL::getStrValue() 
 {
std::stringstream ss; 
ss << this->getValue(); 
return ss.str();
}
void thumbnailURL::takeValue(ResultWrapper* resRwapper) 
 {
std::string value = resRwapper->getString("thumbnailURL");this->setValue(&value);
}
}
}
}
