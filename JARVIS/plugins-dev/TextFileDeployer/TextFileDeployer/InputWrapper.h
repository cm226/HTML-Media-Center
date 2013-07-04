#pragma once

#include <istream>
#include <unordered_set>

class InputWrapper
{
private:
	std::istream& input;
	std::streampos eof;

	std::string buf;
	int bufPosition;

	void readNextChunk();

public:
	InputWrapper(std::istream& input);
	~InputWrapper(void);

	bool isAtEnd();

	std::istream& getRawInput(){return input;}
	char nextChar();
};

