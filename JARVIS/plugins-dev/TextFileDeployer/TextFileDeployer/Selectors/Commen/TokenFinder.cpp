#include "TokenFinder.h"


TokenFinder::TokenFinder(std::string token) : 
	token(token),
	recevedToTokenIndex(0)
{

}


TokenFinder::~TokenFinder(void)
{
}


void TokenFinder::nextChar(InputCharWrapper next)
{
	if(token[recevedToTokenIndex] == next.getChar())
	{
		if(recevedToTokenIndex == 0) tokenStart = next.getPos();
		recevedToTokenIndex ++;
	}
	else
		recevedToTokenIndex = 0;
}

bool TokenFinder::haveToken()
{
	return recevedToTokenIndex == token.length();
}

std::streampos TokenFinder::getTokenStart()
{
	if(haveToken())
		return tokenStart;
	
	return -1;
}