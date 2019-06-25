#include "File.h"

#define INVALID_DATA_SIZE 0

#include <fstream>

File::File(std::shared_ptr<IFileSource> filesource) : _dir("")
{

	this->_dataSource = filesource;
}

File::~File()
{


}

void File::SetLocation(Directory dir, std::string filename)
{
	this->_dir = dir;
	this->_filename = filename;
}

std::string File::Location()
{
	return this->_dir.toString() + this->_filename;
}

std::string File::Name(){
	return this->_filename;
}

bool File::ToString(std::string& str){
	if(!_dataSource)
		return false;

	return _dataSource->GetData(str);
}

bool File::Save()
{
	size_t dataSize = this->_dataSource->GetDataSize();
	if (dataSize == INVALID_DATA_SIZE)
	{
		return false;
	}

	std::vector<unsigned char> data(dataSize);
	bool success = false;

	this->_dataSource->GetData(data);

	char* buffer = (char*)&data[0];

	std::ofstream fileStream(this->_dir.toString() + this->_filename, std::ios::binary | std::ios::out);
	if (fileStream.is_open())
	{
		fileStream.write(buffer, data.size());
		fileStream.close();
		success = true;
	}


	return success;
}