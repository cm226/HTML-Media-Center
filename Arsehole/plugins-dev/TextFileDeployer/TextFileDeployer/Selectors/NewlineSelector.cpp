#include "NewlineSelector.h"


NewlineSelector::NewlineSelector(void)
{
}


NewlineSelector::~NewlineSelector(void)
{
}


std::queue<Selection>& NewlineSelector::nextChar(std::queue<Selection>& selections
		, InputCharWrapper c)
{
	if(c.getChar() == '\n')
		selections.push((Selection(c.getPos(), (int)c.getPos()+1)));

	return selections;
}

std::queue<Selection>& NewlineSelector::inputFinished(std::queue<Selection>& selections, std::streampos end)
{
	return selections;
}
