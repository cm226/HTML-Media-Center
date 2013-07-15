/*
 * SubCatagory.h
 *
 *  Created on: 8 Jul 2013
 *      Author: craig
 */

#ifndef SUBCATAGORY_H_
#define SUBCATAGORY_H_

#include <string>
#include "Field.h"
#include <boost/filesystem.hpp>

namespace ExtendedDatabase {

class SubCatagory {
private:
	std::string _Subcatagoryolder;
	std::string _Name;
public:
	SubCatagory(std::string subCatagoryFolder, std::string name)
	{
		_Subcatagoryolder = subCatagoryFolder;
		_Name = name;
	};
	virtual ~SubCatagory()
	{

	};

	std::string getName(){return _Name;}

	bool fieldExsits(std::string fieldName)
	{
		return boost::filesystem::exists(_Subcatagoryolder+fieldName+".edb");
	};

	template<class K, class V>
	Field<K,V> getField(std::string name)
	{
		return Field<K,V>(_Subcatagoryolder+name+".edb");
	};

};

} /* namespace ExtendedDatabase */
#endif /* SUBCATAGORY_H_ */
