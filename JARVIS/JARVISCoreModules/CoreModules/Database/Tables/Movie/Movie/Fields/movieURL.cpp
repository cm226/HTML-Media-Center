#include "movieURL.h"

namespace DatabaseTables
{

movieURL::movieURL(void) : DatabaseTableField<std::string>("Movie")
{
}


movieURL::~movieURL(void)
{
}

void movieURL::takeValue(ResultWrapper* resRwapper)
{
	this->setValue(&resRwapper->getString("movieURL"));
}

std::string movieURL::getName()
{
	return "Movie.movieURL";
}

std::string movieURL::fieldName()
{
	return "movieURL";
}

std::string movieURL::getStrValue()
{
	return this->getValue();
}

}