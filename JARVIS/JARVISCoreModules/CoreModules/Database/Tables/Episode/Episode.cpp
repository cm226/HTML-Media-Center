#include "Episode.h" 
namespace DatabaseTables{ 
namespace Episode{ 
  Episode::Episode():DatabaseTables::DatabaseTable()
 
 {
this->episodeID = new Fields::episodeID(); 
this->episodeNumber = new Fields::episodeNumber(); 
this->episodeName = new Fields::episodeName(); 
this->episodePlayCount = new Fields::episodePlayCount(); 
this->seasonID = new Fields::seasonID(); 
this->filePath = new Fields::filePath(); 

}
  Episode::~Episode() 
 {
delete this->episodeID;
delete this->episodeNumber;
delete this->episodeName;
delete this->episodePlayCount;
delete this->seasonID;
delete this->filePath;

}
std::string Episode::getUpdateQuery() 
 {
std::stringstream update; 
update << "UPDATE Episode SET ";
return update.str();

}
std::string Episode::getInsertQuery() 
 {
return NULL;
}
void Episode::getFields(std::vector<IDatabaseTableField*>* fields) 
 {
fields->push_back(this->episodeID); 
fields->push_back(this->episodeNumber); 
fields->push_back(this->episodeName); 
fields->push_back(this->episodePlayCount); 
fields->push_back(this->seasonID); 
fields->push_back(this->filePath); 

}
DatabaseTables::IDatabaseTableField* Episode::getPrimaryKey() 
 {
return this->episodeID;
}
std::string Episode::tableName() 
 {
return "Episode";
}
}
}
