#include "MovieName.h"

namespace DatabaseTables
{

MovieName::MovieName(void) :  DatabaseTableField<std::string>("Movie")
{

}


MovieName::~MovieName(void)
{
}

void MovieName::takeValue(ResultWrapper* resRwapper)
{
	this->setValue(&resRwapper->getString("movieName"));

}

std::string MovieName::getName()
{
	return "Movie.movieName";
}

std::string MovieName::fieldName()
{
	return "movieName";
}

std::string MovieName::getStrValue()
{
	return this->getValue();
}


}
