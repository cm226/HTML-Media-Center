#include "Movie.h"
#include <sstream>


namespace DatabaseTables
{

Movie::Movie(void)
{
	this->genra = new movieGenra();
	this->imdb = new movieIMDB();
	//this->length = new movieLength(); not implemented time yet
	this->name = new MovieName();
	this->url = new movieURL();
	this->thumb = new thumbnailURL();
}


Movie::~Movie(void)
{
	delete this->genra;
	delete this->imdb;
	//delete this->length;
	delete this->name;
	delete this->url;
	delete this->thumb;
}

void Movie::getFields(std::vector<IDatabaseTableField*>* fields)
{
	fields->push_back(this->genra);
	fields->push_back(this->imdb);
	fields->push_back(this->name);
	fields->push_back(this->url);
	fields->push_back(this->thumb);
}

std::string Movie::getUpdateQuery()
{
	std::stringstream update;
	update << "UPDATE Movie SET ";

	return update.str();
}

}
