#include "thumbnailURL.h"

namespace DatabaseTables
{


thumbnailURL::thumbnailURL(void) : DatabaseTableField<std::string>("Movie")
{
}


thumbnailURL::~thumbnailURL(void)
{

}

void thumbnailURL::takeValue(ResultWrapper* resRwapper)
{
	this->setValue(&resRwapper->getString("thumbnailURL"));
}


std::string thumbnailURL::getName()
{
	return "Movie.thumbnailURL";
}

std::string thumbnailURL::fieldName()
{
	return "thumbnailURL";
}
std::string thumbnailURL::getStrValue()
{
	return this->getValue();
}



}
