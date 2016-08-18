#pragma once

#include "..\exportMacros.h"
#include "Directory.h"
#include <string>
#include <list>

class DLLCORE_API FileSystem
{
private:
	std::list<Directory> _watched_dirs;


public:
	FileSystem();
	~FileSystem();
	void RetrieveNewFiles(std::string extention,
		std::list<std::wstring>& files);

};