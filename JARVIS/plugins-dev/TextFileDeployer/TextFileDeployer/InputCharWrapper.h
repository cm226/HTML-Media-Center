#pragma once

#include <istream>

class InputCharWrapper
{
private:
	char curChar;
	std::streampos pos;

public:
	InputCharWrapper(char curChar, std::streampos pos);
	~InputCharWrapper(void);

	char getChar(){return curChar;}
	std::streampos getPos(){return pos;}
};

