#include "Base64FileDataURLSource.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"



const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

Base64FileDataURLSource::Base64FileDataURLSource(std::string& fileData)
{
	this->_URLData = std::string(fileData);
}

Base64FileDataURLSource::~Base64FileDataURLSource()
{

}

size_t Base64FileDataURLSource::GetDataSize()
{
	unsigned long lengthCheck = this->_URLData.length() * 0.75;

	if (lengthCheck % 1 != 0)
		ErrorLogger::logError("Base 64 data corrupt, size not divisable by 4");
	else
		return size_t(lengthCheck);

	return 0;

	
}

bool Base64FileDataURLSource::GetData(std::vector<unsigned char>& buffer)
{

	size_t fileLength = this->_URLData.length();
	size_t i = 0;
	int j = 0;

	unsigned int decodedIndex = 0;
	
	for (i = 0; i < fileLength; i++)
	{
			size_t base64Index = base64Chars.find(this->_URLData[i]);
			if (base64Index == std::string::npos)
			{
				ErrorLogger::logError("While decoding Base64 data, illigal charactr found");
				return false;
			}

			switch (j)
			{
			case 0:
				buffer[decodedIndex++] = base64Index << 2; //m
				j++;
				break;
			case 1:
				buffer[decodedIndex - 1] += (base64Index & 48) >> 4;
				buffer[decodedIndex++] = (base64Index & 15) << 4;
				j++;
				break;
			case 2:
				buffer[decodedIndex - 1] += (base64Index & 60) >> 2;
				buffer[decodedIndex++] = (base64Index & 3) << 6;
				j++;
				break;
			case 3:
				buffer[decodedIndex - 1] += base64Index;
				j = 0;
				break;
			}
	}

	return true;
}