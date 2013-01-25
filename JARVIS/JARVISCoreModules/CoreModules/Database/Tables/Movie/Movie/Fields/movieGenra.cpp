#include "movieGenra.h"


namespace DatabaseTables
{

movieGenra::movieGenra(void) : DatabaseTableField<std::string>("Movie")
{
}


movieGenra::~movieGenra(void)
{
}


void movieGenra::takeValue(ResultWrapper* resRwapper)
{
	this->setValue(&resRwapper->getString("movieGenre"));
}

std::string movieGenra::getName()
{
	return "Movie.movieGenre";
}

std::string movieGenra::fieldName()
{
	return "movieGenre";
}

std::string movieGenra::getStrValue()
{
	return this->getValue();
}

}