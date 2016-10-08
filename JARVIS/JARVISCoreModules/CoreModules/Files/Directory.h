#pragma once

#include <string>
#include <list>
#include "../exportMacros.h"

class DLLCORE_API Directory
{
private:
	std::string _location;
public:
	Directory(std::string location);
	~Directory();

	void Search(std::string ext, std::list<std::wstring>& results);
	std::string toString();
};