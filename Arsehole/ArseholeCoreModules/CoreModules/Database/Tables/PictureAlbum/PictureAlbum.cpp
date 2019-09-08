#include "PictureAlbum.h" 
namespace DatabaseTables{ 
namespace PictureAlbum{ 
  PictureAlbum::PictureAlbum():DatabaseTables::DatabaseTable()
 
 {
this->albumName = new Fields::albumName(); 

}
  PictureAlbum::~PictureAlbum() 
 {
delete this->albumName;

}
std::string PictureAlbum::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE PictureAlbum SET ";
return update.str();

}
std::string PictureAlbum::getInsertQuery() 
 {
return NULL;
}
void PictureAlbum::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->albumName); 

}
DatabaseTables::IDatabaseTableField* PictureAlbum::getPrimaryKey() 
 {
return this->albumName;
}
std::string PictureAlbum::tableName() 
 {
return "PictureAlbum";
}
}
}
