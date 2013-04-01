#include "movieID.h"
#include <sstream>

namespace DatabaseTables
{

movieID::movieID(void)  : DatabaseTableField<int>("Movie")
{
}


movieID::~movieID(void)
{
}


void movieID::takeValue(ResultWrapper* resRwapper)
{
	int movieID = resRwapper->getInt("movieID");
	this->setValue(&movieID);
}

std::string movieID::getName()
{
	return "Movie.movieID";
}

std::string movieID::fieldName()
{
	return "movieID";
}

std::string movieID::getStrValue()
{
	std::stringstream ss;
	ss << this->getValue();
	return ss.str();
}


}
