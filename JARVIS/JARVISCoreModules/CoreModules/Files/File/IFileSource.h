#pragma once

#include "../../exportMacros.h"

#include <vector>

class DLLCORE_API IFileSource
{

public:
	virtual bool GetData(std::vector<unsigned char>& buffer) =0;
	virtual size_t GetDataSize() = 0;

};