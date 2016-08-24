#include "Directory.h"

#include <boost/filesystem.hpp>
#include "../../../ErrorLogger/Errors/ErrorLogger.h"

using namespace boost::filesystem;

Directory::Directory(std::string location)
{
	this->_location = location;
	if (!exists(this->_location))
	{
		ErrorLogger::logWarn("FileSystem: Searchable directoyr created that dosn't exist!");
	}
}

Directory::~Directory()
{

}

void Directory::Search(std::string ext, std::list<std::wstring>& results)
{
	if (!exists(this->_location))
		return;

	for (directory_entry& x : directory_iterator(this->_location))
	{
		if (x.path().extension().compare(ext) == 0)
		{
			results.push_back(x.path().generic_wstring());
		}
	}
}
