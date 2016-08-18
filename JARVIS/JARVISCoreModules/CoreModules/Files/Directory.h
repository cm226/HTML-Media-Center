#pragma once

#include <string>
#include <list>

class Directory
{
private:
	std::string _location;
public:
	Directory(std::string location);
	~Directory();

	void Search(std::string ext, std::list<std::wstring>& results);
};