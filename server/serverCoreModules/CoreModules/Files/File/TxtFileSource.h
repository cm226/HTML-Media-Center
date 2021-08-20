#pragma once

#include <string>
#include <vector>

#include "../../exportMacros.h"
#include "IFileSource.h"
#include "../Directory.h"


class DLLCORE_API TxtFileSource : public IFileSource
{
public:

	TxtFileSource(
		std::string location,
		std::string defaultExt = ".txt"
	);

	TxtFileSource(
		Directory dir,
		std::string name,
		std::string defaultExt = ".txt");
	

	virtual bool GetData(std::vector<unsigned char>& buffer) override;

	bool GetData(std::string& buffer) override;
	virtual size_t GetDataSize() override;
	
	std::string ext();

protected:
private:

	std::string m_path;

};