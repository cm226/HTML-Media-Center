#include "ResultWrapper.h"

#include "../../../ErrorLogger/Errors/ErrorLogger.h"

#include "boost/lexical_cast.hpp"

ResultWrapper::ResultWrapper()
	:m_row(nullptr),
	 m_res_set(nullptr),
	 m_unused_row(false)
{
	
}


ResultWrapper::~ResultWrapper(void)
{
}

void ResultWrapper::SetResults(
	MYSQL_RES* res_set
){
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

	// It seems somewhat arbitrary wether implementaions include the table name 
	// in the column map or not, so w/e just support both
	
	if(m_colum_map.find(col_name) != m_colum_map.end()){
		return getString(m_colum_map[col_name]);
	} else {
		auto index = col_name.find_first_of(".");
		if(index != std::string::npos){
			auto col_name_without_table = 
				col_name.substr(index+1);
			if(m_colum_map.find(col_name_without_table) != 
				m_colum_map.end()){
					return getString(m_colum_map[col_name]);
				}
		}
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

bool ResultWrapper::getBoolean(unsigned int col) {

	if(m_row == nullptr){
		ErrorLogger::logError("m_row empty in getBoolean");
		return 0;
	}

	return boost::lexical_cast<bool>(m_row[col]);
}

bool ResultWrapper::getBoolean(std::string col_name) {

	// needs some template love
	if(m_colum_map.find(col_name) != m_colum_map.end()){
		return getBoolean(m_colum_map[col_name]);
	} else {
		auto index = col_name.find_first_of(".");
		if(index != std::string::npos){
			auto col_name_without_table = 
				col_name.substr(index+1);
			if(m_colum_map.find(col_name_without_table) != 
				m_colum_map.end()){
					return getBoolean(m_colum_map[col_name]);
				}
		}
	}

	ErrorLogger::logError(
		"Failed to find column :" + col_name + " in result");
	return false;
}

void ResultWrapper::unNext(){
	m_unused_row = true;
}

bool ResultWrapper::next()
{
	if(m_res_set == nullptr){
		ErrorLogger::logError("no results when moveing next ResultWrapper");
		return false;
	}

	// If the last row was not parsed, then return it now instead of moving on
	if(m_unused_row){
		m_unused_row = false;
		return true;
	}

	m_row = mysql_fetch_row(m_res_set.get());
	return m_row != NULL;
}
