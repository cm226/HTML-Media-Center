#pragma once
#include <string>
#include "../../InputCharWrapper.h"

class TokenFinder
{
private:
	std::streampos tokenStart;
	std::string token;

	int recevedToTokenIndex;


public:
	TokenFinder(std::string token);
	~TokenFinder(void);

	void nextChar(InputCharWrapper next);
	bool haveToken();
	std::streampos getTokenStart();
};

