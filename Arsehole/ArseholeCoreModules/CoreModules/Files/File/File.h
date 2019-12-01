#pragma once

#include "../../exportMacros.h"
#include "IFileSource.h"
#include "../Directory.h"

#include <memory>

class DLLCORE_API File
{
private:
	std::shared_ptr<IFileSource> _dataSource;
protected:
public:
	File(std::shared_ptr<IFileSource> filesource);
	~File();

	bool ToString(std::string& file);


};
