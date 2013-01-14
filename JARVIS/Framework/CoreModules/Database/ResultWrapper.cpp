#include "ResultWrapper.h"


ResultWrapper::ResultWrapper(sql::ResultSet* resSet)
{
	this->resSet = resSet;
}


ResultWrapper::~ResultWrapper(void)
{
	delete this->resSet;
}

int32_t ResultWrapper::getInt(const char* columnName)
{
	return this->resSet->getInt(columnName);
}
double ResultWrapper::getDouble(const char* columnName)
{
	return this->resSet->getDouble(columnName);
}

	
std::string ResultWrapper::getString(const char* columnName)
{
	return this->resSet->getString(columnName);
}

bool ResultWrapper::next()
{
	return this->resSet->next();
}
