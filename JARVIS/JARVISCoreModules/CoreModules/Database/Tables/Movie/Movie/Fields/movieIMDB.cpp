#include "movieIMDB.h"

namespace DatabaseTables
{

movieIMDB::movieIMDB(void) : DatabaseTableField<std::string>("Movie")
{
}


movieIMDB::~movieIMDB(void)
{
}

void movieIMDB::takeValue(ResultWrapper* resRwapper)
{
	this->setValue(&resRwapper->getString("movieIMDB"));
}

std::string movieIMDB::getName()
{
	return "Movie.movieIMDB";
}

std::string movieIMDB::fieldName()
{
	return "movieIMDB";
}

std::string movieIMDB::getStrValue()
{
	return this->getValue();
}

}