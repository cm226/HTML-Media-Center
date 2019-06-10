#pragma once

#include "../../exportMacros.h"
#include "IFileSource.h"
#include "../Directory.h"

#include <memory>

class DLLCORE_API File
{
private:
	std::shared_ptr<IFileSource> _dataSource;
	Directory _dir;
	std::string _filename;
protected:
public:
	File(std::shared_ptr<IFileSource> filesource);
	~File();

	void SetLocation(Directory dir, std::string filename);
	std::string Location();
	std::string Name();
	bool Save();

};
