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
		selections.push((Selection(c.getPos(), c.getPos()+1)));

	return selections;
}
