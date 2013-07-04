#include "InputWrapper.h"


InputWrapper::InputWrapper(std::istream& input) : input(input)
{
	input.seekg(std::ios_base::end);
	this->eof = input.tellg();
	input.seekg(std::ios_base::beg);
}


InputWrapper::~InputWrapper(void)
{
}

bool InputWrapper::isAtEnd()
{
	return input.tellg() == this->eof;
}

void InputWrapper::readNextChunk()
{
	int chunkSize = 100;
	char* tempChar = new char[chunkSize];
	input.read(tempChar,chunkSize);

	buf = tempChar;
	bufPosition = 0;
}

char InputWrapper::nextChar()
{
	char next = buf[bufPosition];
	bufPosition++;
	if(bufPosition == buf.size())
		readNextChunk();

	return next;
}



