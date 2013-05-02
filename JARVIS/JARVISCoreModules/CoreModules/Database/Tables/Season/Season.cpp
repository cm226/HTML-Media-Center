#include "Season.h" 
namespace DatabaseTables{ 
namespace Season{ 
  Season::Season():DatabaseTables::DatabaseTable()
 
 {
this->seasonID = new Fields::seasonID(); 
this->seriesName = new Fields::seriesName(); 
this->seriesNumber = new Fields::seriesNumber(); 

}
  Season::~Season() 
 {
delete this->seasonID;
delete this->seriesName;
delete this->seriesNumber;

}
std::string Season::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Season SET ";
return update.str();

}
std::string Season::getInsertQuery() 
 {
return NULL;
}
void Season::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->seasonID); 
fields->push_back(this->seriesName); 
fields->push_back(this->seriesNumber); 

}
DatabaseTables::IDatabaseTableField* Season::getPrimaryKey() 
 {
return this->seasonID;
}
std::string Season::tableName() 
 {
return "Season";
}
}
}
