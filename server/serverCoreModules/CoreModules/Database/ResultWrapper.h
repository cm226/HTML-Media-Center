#pragma once


#include <string>
#include <memory>
#include <map>
#include <mysql.h>

class ResultWrapper
{
private:
	std::shared_ptr<MYSQL_RES> m_res_set;
	MYSQL_ROW m_row;
	std::map<std::string, int> m_colum_map;

	bool m_unused_row;

public:
	ResultWrapper();
	~ResultWrapper(void);

	void SetResults(MYSQL_RES* resultSet);

	int32_t getInt(const std::string& col_name);
	int32_t getInt(unsigned int col);
	double getDouble(const char* columnName);
	
	std::string getString(std::string col_name);
	std::string getString(unsigned int col);

	bool getBoolean(std::string col_name);
	bool getBoolean(unsigned int col);

	bool next();
	void unNext();

};

