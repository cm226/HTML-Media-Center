#include "movieLength.h"

namespace DatabaseTables
{

movieLength::movieLength(void) : DatabaseTableField<std::string>("Movie")
{
}


movieLength::~movieLength(void)
{
}

void movieLength::takeValue(ResultWrapper* resRwapper)
{
	this->setValue(&resRwapper->getString("movieGenra"));
}

std::string movieLength::getName()
{
	return "Movie.movieGenra";
}

std::string movieLength::fieldName()
{
	return "movieGenra";
}

std::string movieLength::getStrValue()
{
	return "";
}

}