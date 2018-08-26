#include "ResultWrapper.h"

#include "../../../ErrorLogger/Errors/ErrorLogger.h"

ResultWrapper::ResultWrapper(MYSQL_RES* res_set)
	:m_row(nullptr),
	 m_res_set(nullptr)
{
	m_res_set= std::shared_ptr<MYSQL_RES>(
		res_set,
		[](auto p){
			mysql_free_result(p);
		});

	if(res_set == NULL){
		return; 
	}
	
	int col_number = 0;
	MYSQL_FIELD *field;
	while((field = mysql_fetch_field(res_set))) 
	{
		m_colum_map[field->name] = col_number;
		col_number++;
	}
}


ResultWrapper::~ResultWrapper(void)
{
}

int32_t ResultWrapper::getInt(
	const std::string& col_name
) {
	if(m_colum_map.find(col_name) == m_colum_map.end()){
		return getInt(m_colum_map[col_name]);
	}
	
	ErrorLogger::logError(
		"Failed to find column :" + col_name + " in result");
	return 0;

}

int32_t ResultWrapper::getInt(unsigned int col)
{
	if(m_row == nullptr){
		ErrorLogger::logError("m_row empty in getInt");
		return 0;
	}

	return std::stoi(m_row[col]); 
}
double ResultWrapper::getDouble(const char* columnName)
{
	return 0.0;
}

std::string ResultWrapper::getString(
	std::string col_name
){
	if(m_colum_map.find(col_name) == m_colum_map.end()){
		return getString(m_colum_map[col_name]);
	}
	
	ErrorLogger::logError(
		"Failed to find column :" + col_name + " in result");
	return "";
}
	
std::string ResultWrapper::getString(unsigned int col)
{
	if(m_row == nullptr){
		ErrorLogger::logError("m_row empty in getString");
		return 0;
	}

	return std::string(m_row[col]);
}

bool ResultWrapper::next()
{
	if(m_res_set == nullptr){
		ErrorLogger::logError("no results when moveing next ResultWrapper");
		return false;
	}

	m_row = mysql_fetch_row(m_res_set.get());
	return m_row != NULL;
}
