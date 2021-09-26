#include "Series.h" 
namespace DatabaseTables{ 
namespace Series{ 
  Series::Series():DatabaseTables::DatabaseTable()
 
 {
this->seriesName = new Fields::seriesName(); 
this->seriesIMDB = new Fields::seriesIMDB(); 
this->seriesGenre = new Fields::seriesGenre(); 

}
  Series::~Series() 
 {
delete this->seriesName;
delete this->seriesIMDB;
delete this->seriesGenre;

}
std::string Series::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Series SET ";
return update.str();

}
std::string Series::getInsertQuery() 
 {
return NULL;
}
void Series::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->seriesName); 
fields->push_back(this->seriesIMDB); 
fields->push_back(this->seriesGenre); 

}
DatabaseTables::IDatabaseTableField* Series::getPrimaryKey() 
 {
return this->seriesName;
}
std::string Series::tableName() 
 {
return "Series";
}
}
}
