/*
 * Catagory.cpp
 *
 *  Created on: 8 Jul 2013
 *      Author: craig
 */

#include "Catagory.h"
#include <boost/filesystem.hpp>

namespace ExtendedDatabase {

Catagory::Catagory(std::string catagoreysFolder) :
		_CatagorysFolder(catagoreysFolder)
{
	namespace fs = boost::filesystem;
	fs::path pluginDirectory(_CatagorysFolder);
	fs::directory_iterator end_iter;


	for( fs::directory_iterator dir_iter(pluginDirectory) ; dir_iter != end_iter ; ++dir_iter)
	{
		if (fs::is_directory( *dir_iter ))
		{
			fs::path path = dir_iter->path();
			std::string subCatFolder = path.string();
			std::string subCatFolderName(path.leaf().string());

			_SubCatagories.push_back(SubCatagory(subCatFolder, subCatFolderName));
		}
	}
}

Catagory::~Catagory() {

}

void Catagory::addSubCatagory(std::string catagoryName)
{
	if(!boost::filesystem::exists(catagoryName))
	{
		std::string catagoryFolder =_CatagorysFolder+"\\"+catagoryName;
		boost::filesystem::create_directory(catagoryFolder);
		_SubCatagories.push_back(SubCatagory(catagoryFolder, catagoryName));
	}
}

bool Catagory::tryLookupSubcatagoryFromName(std::string name, SubCatagory& subCat)
{
	//TODO change the list of subcatagorys to a hashmap of there names
	for(std::list<SubCatagory>::iterator subCatIt = _SubCatagories.begin();
			subCatIt != _SubCatagories.end(); subCatIt++)
	{
		if(name.compare(subCatIt->getName()) == 0)
		{
			subCat = *subCatIt;
			return true;
		}
	}

	ErrorLogger::logWarn("looking up a sub category that doesn't exist in Extended database:"+ name);
	return false;

}
const std::list<SubCatagory>& Catagory::ListSubCatagories()
{
	return _SubCatagories;
}

} /* namespace ExtendedDatabase */
