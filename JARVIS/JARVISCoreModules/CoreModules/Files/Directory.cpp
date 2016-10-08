#include "Directory.h"

#include <boost/filesystem.hpp>
#include "../../../ErrorLogger/Errors/ErrorLogger.h"

using namespace boost::filesystem;

Directory::Directory(std::string location)
{
	std::replace(location.begin(), location.end(), '\\', '/');
	if (location.length() >0 && location.back() != '/')
		location.append("/");

	this->_location = location;
	if (!exists(this->_location))
	{
		ErrorLogger::logWarn("FileSystem: Searchable directory created that dosn't exist! : " +
			this->_location);
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

std::string Directory::toString()
{
	return this->_location;
}
