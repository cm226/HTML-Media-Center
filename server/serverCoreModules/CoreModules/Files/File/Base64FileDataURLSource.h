#pragma once

#include <string>
#include <vector>

#include "../../exportMacros.h"
#include "IFileSource.h"



class DLLCORE_API Base64FileDataURLSource : public IFileSource
{
public:

	Base64FileDataURLSource(std::string& base64Data);
	~Base64FileDataURLSource();

	virtual bool GetData(std::vector<unsigned char>& buffer);
	virtual size_t GetDataSize();
protected:
private:

	std::string _URLData;

};