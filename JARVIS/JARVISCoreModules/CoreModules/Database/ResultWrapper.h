#pragma once

#include <cppconn/resultset.h>
#include <string>

class ResultWrapper
{
private:
	sql::ResultSet* resSet;

public:
	ResultWrapper(sql::ResultSet* resSet);
	~ResultWrapper(void);

	int32_t getInt(const char* columnName);
	double getDouble(const char* columnName);
	
	std::string getString(const char* columnName);

	bool next();

};

