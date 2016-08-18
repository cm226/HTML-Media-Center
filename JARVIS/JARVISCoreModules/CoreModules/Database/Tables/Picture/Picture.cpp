#include "Picture.h" 
namespace DatabaseTables{ 
namespace Picture{ 
  Picture::Picture():DatabaseTables::DatabaseTable()
 
 {
this->picName = new Fields::picName(); 
this->picURL = new Fields::picURL(); 
this->albumName = new Fields::albumName(); 

}
  Picture::~Picture() 
 {
delete this->picName;
delete this->picURL;
delete this->albumName;

}
std::string Picture::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Picture SET ";
return update.str();

}
std::string Picture::getInsertQuery() 
 {
return NULL;
}
void Picture::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->picName); 
fields->push_back(this->picURL); 
fields->push_back(this->albumName); 

}
DatabaseTables::IDatabaseTableField* Picture::getPrimaryKey() 
 {
return this->picURL;
}
std::string Picture::tableName() 
 {
return "Picture";
}
}
}
